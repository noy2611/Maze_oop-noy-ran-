#include "mymodal.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include "Maze2d.h" 

void MazeManager::saveMazeToFile(std::string mazeName, const Maze2d& maze) {
    // Create a file stream and open the file for writing
    std::ofstream outFile(mazeName + ".txt");

    if (outFile.is_open()) {
        // Write each cell of the maze to the file
        for (int i = 0; i < maze.getRows(); i++) {
            for (int j = 0; j < maze.getColumns(); j++) {
                outFile << maze.getCell(i, j)<< " ";
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


///////load


void MazeManager::loadAndProcessFile(const std::string& filePath) {
    std::ifstream inFile(filePath); // Open the file for reading

    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl; // Print each line to the console
        }

        inFile.close(); // Close the file
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}









