#pragma once
#include <string>
#include <vector>
#include <map>


using namespace std;

class MazeManager {
private:
    std::map<std::string, std::vector<std::string>> mazeMap;

public:
    void saveMaze(std::string mazeName, char** maze, int M, int N);
    void printMaze(std::string mazeName);
};