#include "Command.h"
#include "myView.h"

class dircommand : public Command
{
private:
    dirview dir;

public:
    void execute(const vector<string> &CommandName) override
    {
        if (CommandName.size() >= 2)
        {
            // Extract the second element from the vector
            string secondWord = CommandName[1];
            dir.displayFilesAndFolders(secondWord);
        }

        //     cout << "Second word: " << secondWord << endl;
        // } else {
        //     cout << "CommandName does not have a second word." << endl;
        // }
    }
};
