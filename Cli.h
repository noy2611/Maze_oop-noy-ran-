#pragma once
#pragma once
#include <iostream>
#include <string>
#include <map>
#include "myController.h"
#include <iostream>
#include <string>
using namespace std;

class Cli : public myController
{
private:
    /* data */
public:
    Cli(/* args */){};
    ~Cli(){};
    void start();
};

