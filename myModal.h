#pragma once
#include <string>
#include <vector>
#include <map>
#include "Maze2d.h"

using namespace std;

class MazeManager {
private:
    std::map<std::string, std::vector<std::string>> mazeMap;

public:
void saveMazeToFile(std::string mazeName, const Maze2d& maze);
void loadMazeFromFile(std::string mazeName, Maze2d& maze);
    // void printMaze(std::string mazeName);
};
