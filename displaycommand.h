#include "Command.h"
#include "Maze2d.h"

class displaycommand : public Command
{
private:
    Maze2d disp;

public:
    displaycommand(const Maze2d& maze) : disp(maze) {}

    void execute(const vector<string> &CommandName) override {
        disp.display(); // Call the display function of Maze2d
    }
};
