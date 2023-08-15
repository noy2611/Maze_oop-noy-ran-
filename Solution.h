#pragma once
#include <iostream>
#include <vector>
#include "State.h"

template <class T>
class Solution
{
public:
    Solution() : found(false) {}
    ~Solution() {}

    void addState(const State<T>* state)
    {
        m_solution.push_back(state);
    }

    bool isSolutionFound() const
    {
        return found;
    }

    void setSolutionFound(bool value)
    {
        found = value;
    }

private:
    std::vector<const State<T>*> m_solution;
    bool found;
};