#pragma once
#include "myController.h"
#include "myModal.h"
#include <vector>
#include <string>


class Command
{
public:
    virtual void execute(const vector<string> &CommandName) = 0;
    virtual ~Command() {}
};