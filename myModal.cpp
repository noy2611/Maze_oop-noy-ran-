#include "mymodal.h"
#include <iostream>

void MazeManager::saveMaze(std::string mazeName, char** maze, int M, int N) {
    std::vector<std::string> mazeRows;
    for (int i = 0; i < M; i++) {
        std::string row = maze[i];
        mazeRows.push_back(row);
    }
    mazeMap[mazeName] = mazeRows;
}

// void MazeManager::printMaze(std::string mazeName) {
//     if (mazeMap.find(mazeName) != mazeMap.end()) {
//         std::cout << "Maze " << mazeName << ":" << std::endl;
//         for (const std::string& row : mazeMap[mazeName]) {
              
//             std::cout << row << std::endl;
            
//         }
//     } else {
//         std::cout << "Maze " << mazeName << " not found!" << std::endl;
//     }
// }

void MazeManager::printMaze(std::string mazeName) {
    if (mazeMap.find(mazeName) != mazeMap.end()) {
        std::cout << "Maze " << mazeName << ":" << std::endl;
        for (const std::string& row : mazeMap[mazeName]) {
            for (char c : row) {
                std::cout << c << ' '; // Print the character and a space
            }
            std::cout << std::endl; // Move to the next line after the row
        }
    } else {
        std::cout << "Maze " << mazeName << " not found!" << std::endl;
    }
}
