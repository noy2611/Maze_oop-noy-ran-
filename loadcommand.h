#include "Command.h"
#include "myModal.h"
#include <string>
#include <vector>
#include <map>
#include "displaycommand.h"
#pragma once

class loadcommand : public Command
{

public:
    void execute(const vector<string> &CommandName) override
    {

        if (CommandName.size() < 3)
        {
            cout << "Not enough arguments for load command." << endl;
            return;
        }

        string mazeName = CommandName[1];
        string filePath = CommandName[2];

        cout << "Loading maze: " << mazeName << " from file: " << filePath << endl;

        Maze2d mazeToLoad;
        MazeManager::loadFile(filePath, mazeToLoad);
        // mazeToLoad.display();
          std::vector<std::string> displayArgs = {"display", mazeName};

//     // Call the execute function for displaying the maze
    
    MazeManager::addMazeData(mazeName,mazeToLoad);
displaycommand displayCommand;
    displayCommand.execute(displayArgs);
    }
};
