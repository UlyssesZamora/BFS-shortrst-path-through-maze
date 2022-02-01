#include<sstream>
#include<algorithm>
#include<math.h>
#include"bfs.h"

using std::stringstream;

Bfs::Bfs(string maze) :
  maze(maze), size(sqrt(maze.length()))
{
  color = new Color[size*size];
  parent = new int[size*size];
  distance = new int[size*size];
  for (int i = 1; i < size*size; i++)
    {
      color[i] = white;
      parent[i] = -1;
      distance[i] = -1;
    }
  color[0] = gray;
  parent[0] = -1;
  distance[0] = 0;
  q.push(0);

  while (!q.empty())
    {
      int temp = q.front();
      vector<int> adj = getAdjacent(temp);
      for (int i = 0; i < adj.size(); i++)
	{
	    int v = adj[i];
	  if (color[v] == white)
	    {
	      color[v] = gray;
	      distance[v] = distance[temp] + 1;
	      parent[v] = temp;
	      q.push(v);
	    }
	}
      q.pop();
      color[temp] = black;
    }
}

vector<string> Bfs::Path()
{
  vector<string> result;
  if (distance[size*size-1] == -1) return result;
  int temp = size*size-1;
  while (temp != -1)
    {
      stringstream coords;
      coords << '(' << temp%size << ", " << temp/size << ')';
      result.push_back(coords.str());
      temp = parent[temp];
    }
  std::reverse(result.begin(), result.end());
  return result;
}

char Bfs::getSharedWall(int x, int y)
{
  if (!bCheck(x) || !bCheck(y) ||!isAdj(x, y)) return 0;
  if (y == x) return 0;
  if (y == x+1) return 1;
  if (y == x+size) return 2;
  if (y == x-1) return 4;
  if (y == x-size) return 8;
}

char Bfs::getWalls(int x)
{
  if (!bCheck(x)) return -1;
  int value = hexToInt(maze[x]);
  if (value == -1) return -1;
  return (char)(hasRight(value) | (hasBottom(value)<<1) | (hasLeft(value)<<2) | (hasTop(value)<<3));
}

int Bfs::hexToInt(char hex)
{
  if (hex >= 48 && hex <= 57)
    return hex - 48;
  else if (hex >= 97 && hex <= 102)
    return hex - 97 + 10;
  return -1;
}

bool Bfs::hasWallBetween(int x, int y)
{
  return getSharedWall(x, y) & getWalls(x);
}

bool Bfs::isConnected(int x, int y)
{
  return isAdj(x, y) && !hasWallBetween(x, y); /*bounsd check included in
						 isAdj.*/
}

vector<int> Bfs::getAdjacent(int x)
{
  vector<int> result;
  if (!bCheck(x)) return result;
  if (isConnected(x, x+1)) result.push_back(x+1);
  if (isConnected(x, x-1)) result.push_back(x-1);
  if (isConnected(x, x-size)) result.push_back(x-size);
  if (isConnected(x, x+size)) result.push_back(x+size);
}
