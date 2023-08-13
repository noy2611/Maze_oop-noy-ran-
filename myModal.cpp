#include "mymodal.h"
#include <iostream>
#include <fstream>
#include "Maze2d.h" 

void MazeManager::saveMazeToFile(std::string mazeName, const Maze2d& maze) {
    // Create a file stream and open the file for writing
    std::ofstream outFile(mazeName + ".txt");

    if (outFile.is_open()) {
        // Write each cell of the maze to the file
        for (int i = 0; i < maze.getRows(); i++) {
            for (int j = 0; j < maze.getColumns(); j++) {
                outFile << maze.getCell(i, j);
            }
            outFile << "\n"; // Write a newline character after each row
        }

        // Close the file
        outFile.close();
        std::cout << "Maze saved to " << mazeName << ".txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}






// void MazeManager::saveMaze(std::string mazeName, char** maze, int M, int N) {
//     std::vector<std::string> mazeRows;
//     for (int i = 0; i < M; i++) {
//         std::string row = maze[i];
//         mazeRows.push_back(row);
//     }
//     mazeMap[mazeName] = mazeRows;
// }

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

// void MazeManager::printMaze(std::string mazeName) {
//     if (mazeMap.find(mazeName) != mazeMap.end()) {
//         std::cout << "Maze " << mazeName << ":" << std::endl;
//         for (const std::string& row : mazeMap[mazeName]) {
//             for (char c : row) {
//                 std::cout << c << ' '; // Print the character and a space
//             }
//             std::cout << std::endl; // Move to the next line after the row
//         }
//     } else {
//         std::cout << "Maze " << mazeName << " not found!" << std::endl;
//     }
// }
