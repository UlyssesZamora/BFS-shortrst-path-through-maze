#ifndef BFS_H
#define BFS_H
#include<string>
#include<vector>
#include<queue>


using std::string;
using std::vector;
using std::queue;

enum Color { white, gray, black };

class Bfs
{
 public:
  Bfs(string maze);
  vector<string> Path();
  ~Bfs() { delete[] color; delete[] parent; delete[] distance; }
 private:
  string maze;
  int size;
  Color* color;
  int* parent;
  int* distance;
  queue<int> q;
  bool hasWallBetween(int x, int y);
  vector<int> getAdjacent(int x);
  char getSharedWall(int x, int y);
  int hexToInt(char hex);
  char getWalls(int x);
  bool isConnected(int x, int y);
  bool bCheck(int x) { return x >= 0 && x < size*size; }
  bool isAdj(int x, int y)
  {
    int rowX = x/size, rowY = y/size,
      colX = x%size, colY = y%size;
    return bCheck(x) && bCheck(y) && std::abs(rowX-rowY) + std::abs(colX-colY) == 1;
  }
  bool hasRight(int x) { return x % 2 == 1; }
  bool hasLeft(int x) { return (x-4 >= 0 && x-4 <= 3) ||
      (x-12 >= 0 && x-12 <= 15); }
  bool hasTop(int x) { return x >= 8 && x <= 15; }
  bool hasBottom(int x) { return x % 4 == 2 || x % 4 == 3; }

};



#endif
