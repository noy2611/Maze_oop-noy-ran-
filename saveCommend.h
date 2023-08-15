#include "Command.h"
#include "myModal.h"
#include <string>
#include <vector>
#include <map>

#pragma once
class saveCommend :public Command
{
private:

public:
   void execute(const vector<string> &CommandName) override
    {
           if (CommandName.size() < 2)
        {
            cout << "Not enough arguments for save command." << endl;
            return;
        }

        string mazeName = CommandName[1];
        MazeManager::saveMazeToFile(mazeName, MazeManager::getMaze(mazeName));
        cout << "Maze saved." << endl;
    }
};


