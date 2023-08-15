#pragma once
#include "Maze2d.h"

class Maze2dGenerator
{
private:
    int startTime;
    int endTime;

public:
    Maze2dGenerator(/* args */){};
    virtual ~Maze2dGenerator(){};
    string mesureAlgorithemTime(int start, int end);//to dooooo
    virtual Maze2d generate(int M, int N, Maze2d maze) = 0;
};

