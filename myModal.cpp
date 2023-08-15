#include <iostream>
#include <fstream>
#include <sstream>
#include "Maze2d.h"
#include "myModal.h"

void MazeManager::saveMazeToFile(std::string mazeName, const Maze2d &maze)
{
    // Create a file stream and open the file for writing
    std::ofstream outFile(mazeName + ".txt");

    if (outFile.is_open())
    {
        // Write each cell of the maze to the file
        for (int i = 0; i < maze.getRows(); i++)
        {
            for (int j = 0; j < maze.getColumns(); j++)
            {
                outFile << maze.getCell(i, j);
            }
            outFile << "\n"; // Write a newline character after each row
        }

        // Close the file
        outFile.close();
        std::cout << "Maze saved to " << mazeName << ".txt" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

///////load

void MazeManager::loadFile(const std::string &filePath, Maze2d &maze)
{
    std::ifstream mazeFile(filePath);
    if (!mazeFile)
    {
        std::cerr << "Error opening maze file." << std::endl;
        return;
    }

    int rows = 0;
    int columns = 0;
    std::vector<std::string> mazeData; // Store the maze data as strings

    // Read the entire maze file into mazeData vector
    std::string line;
    while (getline(mazeFile, line))
    {
        mazeData.push_back(line);
        if (line.length() > columns)
        {
            columns = line.length();
        }
        rows++;
    }
    // cout<<rows<<" "<<columns<<endl;
    mazeFile.clear();
    mazeFile.seekg(0, std::ios::beg);
    // Extract the filename from the filePath
    std::string mazeName = filePath.substr(filePath.find_last_of("/\\") + 1);
    mazeName = mazeName.substr(0, mazeName.find_last_of('.'));
    // Set the maze name
    maze.setName(mazeName);

    maze.setRows(rows);
    maze.setColumns(columns);
    maze.createMazeGrid(); // Allocate memory for the maze grid

    // Populate the maze grid from the file
    for (int i = 0; i < rows; i++)
    {
        const std::string &currentLine = mazeData[i];
        for (int j = 0; j < columns; j++)
        {
            if (j < currentLine.length())
            {
                maze.setCell(i, j, currentLine[j]);
            }
            else
            {
                maze.setCell(i, j, ' '); // Set spaces for missing cells
            }
        }
    }
    maze.setCurrentPosition(0,1);
    mazeFile.close();
}
/// filesize

size_t MazeManager::calculateFileSize(const std::string &filePath)
{
    std::ifstream inFile(filePath, std::ios::binary | std::ios::ate); // Open the file in binary mode and position at the end

    if (inFile.is_open())
    {
        // Get the current position (which is the size of the file)
        size_t fileSize = inFile.tellg();

        inFile.close(); // Close the file

        if (fileSize > 0)
        {
            cout << "Size of the maze file: " << fileSize << " bytes" << endl;
        }

        return fileSize;
    }
    else
    {
        cerr << "Unable to open file." << endl;
        return 0; // Return 0 on error
    }
}


//get maze
 Maze2d MazeManager::getMaze(const std::string& mazeName) {
    auto it = mazeMap.find(mazeName);
    if (it != mazeMap.end()) {
        return it->second;
    } else {
        Maze2d emptyMaze; // Create a default-constructed Maze2d object
        return emptyMaze;
    }
}


//save to hashmap

 void MazeManager::addMazeData(const std::string& mazeName, const Maze2d& maze) {
    // Check if the maze name already exists in the mazeMap
    if (mazeMap.find(mazeName) == mazeMap.end()) {
        // Maze with the given name doesn't exist, add the new maze
        mazeMap[mazeName] = maze;
    } else {
        std::cout << "Maze with name " << mazeName << " already exists." << std::endl;
    }
}

map<string, Maze2d> MazeManager::mazeMap;
