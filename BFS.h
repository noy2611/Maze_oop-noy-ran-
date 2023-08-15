#pragma once
#include <queue>
#include "CommonSearcher.h"

template <class T>
class BFS : public CommonSearcher<T>
{
public:
    virtual Solution<T> search(const Searchable<T> &s) override
    {
        this->addToOpenList(s.getStartState()); 

        while (!this->m_openList.empty())
        {
            const State<T> &currentState = this->popOpenList();
            State<T> currentStateCopy = currentState; // Create a copy to work with

            // If the current state is the goal state, backtrack and create the solution
            if (currentState == *s.getGoalState())
            {
                return this->backtrackSolution(currentState);
            }

            // Get all possible states from the current state
            const std::vector<State<T> *> *possibleStates = s.getAllPossibleStates(currentStateCopy);
            currentStateCopy.printState();
            
            for (State<T> *nextState : *possibleStates)
            {
                // Check if the next state is not already in the open list
                if (!this->isInOpenList(*nextState))
                {   
                    this->addToOpenList(nextState);
                    
                    nextState->setCameFrom(&currentStateCopy); // Set the cameFrom for the copy
                    
                }
                else
                {
                    delete nextState; // Clean up memory for states that are not added to the open list
                }
            }

            delete possibleStates;
        }

        return Solution<T>(); // No solution found
    }
};
