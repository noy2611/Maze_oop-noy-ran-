#pragma once
#include <string>
#include <vector>
#include <map>
#include "Maze2d.h"

using namespace std;

class MazeManager
{
private:
    // std::map<std::string, std::vector<std::string>> mazeMap;
    map<string, Maze2d> mazeMap;

public:
    void saveMazeToFile(std::string mazeName, const Maze2d &maze);
    void loadFile(const std::string &filePath, Maze2d &maze);
    size_t calculateFileSize(const std::string &filePath);
    void addMazeData(const std::string &mazeName, const Maze2d &maze);
    Maze2d getMaze(const std::string &mazeName);
};
