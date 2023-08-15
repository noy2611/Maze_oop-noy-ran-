#pragma once

#include <vector>
#include "State.h"

template <class T>
class Searchable
{
public:
    virtual State<T> *getStartState() const = 0;
    virtual State<T> *getGoalState() const = 0;

    // Return a vector of pointers to State instances
    virtual std::vector<State<T> *> *getAllPossibleStates(const State<T> &s) const = 0;
};
