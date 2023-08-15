#include "Command.h"
#include "Maze2d.h"
#include "myModal.h"
#pragma once

class displaycommand : public Command
{
private:
    
public:

    void execute(const vector<string> &CommandName) override
    {  
        
       if (CommandName.size() < 2) {
            cout << "Not enough arguments for display command." << endl;
            return;
        }
    
        string mazeName = CommandName[1]; 
        Maze2d mazeToDisplay = MazeManager::getMaze(mazeName);
        mazeToDisplay.display();
    }
};
