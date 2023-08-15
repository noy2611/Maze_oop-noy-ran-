#include "Command.h"
#include "myMaze2dGenerator.h"
#include "myModal.h"

#pragma once

class mymaze2dGeneratorCommand : public Command
{
private:
    myMaze2dGenerator generator; // Create an instance of myMaze2dGenerator
    // map<string, Maze2d> AllmazeMap;

public:
    //  Maze2d generate(int M, int N, Maze2d maze);
    void execute(const vector<string> &CommandName) override
    {
       
        if (CommandName.size() < 3)
        {
            
            cout << "Not enough arguments for generate command." << endl;
            return;
        }
        string name = CommandName[2];
        int m = stoi(CommandName[0]); // Extract M value from CommandName
        int n = stoi(CommandName[1]); // Extract N value from CommandName
       
        int M = 2 * m + 1;
        int N = 2 * n + 1;
        Maze2d maze(M, N, name); // Create a Maze2d instance with dimensions M and N
       
        maze.setCell(0, 1, 'S');
        maze.setCell(2 * m, 2 * n - 1, 'E');
        
        // Call the generate function from myMaze2dGenerator class
        Maze2d generatedMaze = generator.generate(M, N, maze);
      
        //check print
        // generatedMaze.display();
        MazeManager mazemanager;
        mazemanager.addMazeData(name,generatedMaze);

    }
};
