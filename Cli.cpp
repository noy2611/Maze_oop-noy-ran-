#include "Cli.h"
#include<istream>
#include<string>
using namespace std;
void Cli::start()
{    string text;
    while (true)
    {
        cout << "welcome to maze" << endl;
        cout << "you need to write the command you wish to activate" << endl;
        cout << "possible Commands to choose:" << endl;
        cout << "1) dir path"
             << "\t\t"
             << "2) generate maze <rows> <columns> <name>" << endl;
        cout << "3) display name"
             << "\t"
             << "4) save maze name" << endl;
        cout << "5) load maze name"
             << "\t"
             << "6) maze size name" << endl;
        cout << "7) file size name"
             << "\t"
             << "8) play maze name" << endl;
        cout << ">";

            getline(cin, text);
            if (text == "quit")
            {
                break;
            }
            

    }
}