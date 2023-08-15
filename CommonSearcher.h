#pragma once
#include "Searcher.h"
#include <queue>
#include <chrono> // for measuring time
#include <unordered_map> 

template <class T>
class CommonSearcher : public Searcher<T>
{
private:
    std::unordered_map<const State<T>*, bool> m_visited;
public:
    CommonSearcher() : m_evaluatedNodes(0) {}

    // Abstraction
public:
    virtual Solution<T> search(const Searchable<T> &s) = 0;
    virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };

    // Measure and print the efficiency of the search algorithm
    void checkEfficiency(const Searchable<T> &s)
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        Solution<T> solution = search(s);

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        std::cout << "Search time: " << duration.count() << " ms" << std::endl;

        if (solution.isSolutionFound())
        {
            std::cout << "Solution found!" << std::endl;
        }
        else
        {
            std::cout << "No solution found!" << std::endl;
        }

        std::cout << "Nodes evaluated: " << getNumberOfNodesEvaluated() << std::endl;
    }

    // Additional implementation
public:
    const State<T> &popOpenList()
    {
        m_evaluatedNodes++;
        const State<T> &topState = m_openList.top();
        m_openList.pop();
        m_visited[&topState] = true; // Mark as visited and processed
        return topState;
    }

    Solution<T> backtrackSolution(const State<T> &goalState)
    {
        Solution<T> solution;
        const State<T> *backState = &goalState;
        while (backState != nullptr)
        {
            solution.addState(backState);
            backState = backState->getCameFrom();
        }
        solution.setSolutionFound(true);
        return solution;
    }

     void addToOpenList(const State<T> *state)
    {
        State<T> *nonConstState = const_cast<State<T> *>(state);
        m_openList.push(*nonConstState);
        m_visited[state] = false; // Mark as visited but not processed yet
    }

    bool isInOpenList(const State<T> &state) const
    {
        auto it = m_visited.find(&state);
        return it != m_visited.end() && !it->second;
    }

protected:
    int m_evaluatedNodes;
    mutable std::priority_queue<State<T>> m_openList;
};