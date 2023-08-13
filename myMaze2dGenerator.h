#pragma once
#include "Maze2dGenerator.h"
#include <stack>
#include <vector>
#include <random>

class myMaze2dGenerator : public Maze2dGenerator
{
private:
    /* data */
public:
    myMaze2dGenerator(/* args */){};
    ~myMaze2dGenerator(){};
    Maze2d generate(int M, int N, Maze2d maze);
};


