#pragma once
#include <iostream>
#include <string>
#include <vector>
 using namespace std;

class Maze2d
{
private:
   string mazeName; 
   int rows;
   int columns;
   int size;
   char **maze;
   vector<pair<int, pair<int, int>>> cell_list;
public:
    Maze2d(/* args */);
    ~Maze2d();
};

Maze2d::Maze2d(/* args */)
{
}

Maze2d::~Maze2d()
{
}
