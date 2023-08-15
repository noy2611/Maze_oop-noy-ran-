// #pragma once
// #include <map>
// #include <string>
// #include <functional>
// #include "Command.h"
// // vהוספת כל הקומנד שנעשההההההההההההההההההה

// #pragma once
// using namespace std;

// class myController
// {
// private:
//     map<string, Command *> commands;
//    map<string, std::function<void()>> m_functions;

// public:
//     myController(/* args */);
//     ~myController();

//     Command *get(const string &command)
//     {
//         auto it = commands.find(command);
//         if (it == commands.end())
//             return nullptr;

//         return it->second;
//     }

//     std::function<void()> *getF(const string &command)
//     {
//         auto it = m_functions.find(command);
//         if (it == m_functions.end())
//             return nullptr;

//         return &(it->second);
//     }
// };




// #pragma once

// #include <map>
// #include <string>
// #include <vector>
// #include <iostream>
// #include "Command.h"
// #include "displaycommand.h" // Include the header for the displaycommand
// #include "myModal.h"
// #include "myView.h"

// using namespace std;

// class myController {
// private:
//     map<string, Command *> commands;

// public:
//  void setupCommands() {
//         // Create instances of your commands and add them to the map
//         commands["display"] = new displaycommand();
//         // ... add other commands ...
//     }



//     myController() {
//         setupCommands(); // Call this in the constructor to set up the commands
//     }

//     void setupCommands() {
//         // Create instances of your commands and add them to the map
//         commands["display"] = new displaycommand();
//         // ... add other commands ...
//     }

//     void executeCommand(const string &commandName, const vector<string> &args) {
//         // Find the command in the map and execute it
//         auto it = commands.find(commandName);
//         if (it != commands.end()) {
//             Command *cmd = it->second;
//             cmd->execute(args);
//         } else {
//             cout << "Command not found." << endl;
//         }
//     }
//     myController::myController() {
//     setupCommands();
// }

// };
