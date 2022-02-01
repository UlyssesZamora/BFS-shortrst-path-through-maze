#include<iostream>
#include"bfs.h"

int main()
{
  string maze;
  string temp;
  while (std::cin >> temp) //assuming maze input is lowercase.
    maze += temp;
  Bfs bfs(maze);
  vector<string> path = bfs.Path();
  for (int i = 0; i < path.size(); i++)
    std::cout << path[i] << '\n';
}
