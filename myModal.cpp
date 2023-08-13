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


void MazeManager::loadMazeFromFile(std::string mazeName, Maze2d& maze) {
    // Open the file for reading
    std::ifstream inFile(mazeName + ".txt");
    
    if (inFile.is_open()) {
        // Read each line (row) from the file
        for (int i = 0; i < maze.getRows(); i++) {
            std::string row;
            std::getline(inFile, row);
            
            // Ensure the row length matches the number of columns in the maze
            if (row.length() != maze.getColumns()) {
                std::cerr << "Error: Invalid row length in maze file." << std::endl;
                return;
            }
            
            // Fill the maze cells with the characters from the row
            for (int j = 0; j < maze.getColumns(); j++) {
                maze.setCell(i, j, row[j]);
            }
        }
        
        // Close the file
        inFile.close();
        maze.setName(mazeName); // Set the maze name after loading
        cout << "Maze loaded from " << mazeName << ".txt" <<endl;
    } else {
       cerr << "Unable to open file for reading." << endl;
    }
}










