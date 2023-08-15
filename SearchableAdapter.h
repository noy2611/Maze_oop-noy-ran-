#pragma once
#include "Searchable.h"
#include "Maze2d.h"
using namespace std;

class SearchableAdapter : public Searchable<Maze2d>
{
private:
    Maze2d maze;

public:
    SearchableAdapter(const Maze2d &maze) : maze(maze) {}
    ~SearchableAdapter() {}

    State<Maze2d> *getStartState() const override
    {
        // Get the starting state from the Maze2d instance
        State<Maze2d> *startState = new State<Maze2d>(maze);
        startState->setCost(0); // Set the cost to 0 for the starting state
        // startState->printState();
        return startState;
    }

    State<Maze2d> *getGoalState() const override
    {
        // Get the goal position from the current maze
        pair<int, int> goalPosition = maze.getGoalPosition();
        // Create a copy of the maze
        Maze2d goalMaze = maze;
        // Set the end symbol at the goal position
        goalMaze.setCell(goalPosition.first, goalPosition.second, 'E');
        // Create a new State instance with the modified maze
        State<Maze2d> *goalState = new State<Maze2d>(goalMaze);
        // Set the cost to 0 for the goal state
        goalState->setCost(0);
        // goalState->printState();
        return goalState;
    }

    std::vector<State<Maze2d> *> *getAllPossibleStates(const State<Maze2d> &s) const override
    {
        std::vector<State<Maze2d> *> *possibleStates = new std::vector<State<Maze2d> *>();

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, down, left, right

        int currentRow = s.getState().getCurrentRow();
        int currentCol = s.getState().getCurrentColumn();

   for (const auto &direction : directions)
{
    int newRow = currentRow + direction[0];
    int newCol = currentCol + direction[1];

    // Check if the new position is valid and not a wall
    if (maze.isValidMove(s.getState(), newRow, newCol))
    {
        // Update the current position for the next iteration
        s.getState().setCurrentRow(newRow);
        s.getState().setCurrentColumn(newCol);

        Maze2d newMaze = s.getState();
        // Set the cell only if the move is valid
        newMaze.setCell(newRow, newCol, 'S');

        State<Maze2d> *newState = new State<Maze2d>(newMaze);
        newState->setCost(s.getCost() + 1);
        newState->setCameFrom(&s);

        possibleStates->push_back(newState);

        // Check if the new position is the end of the maze ('E')
        if (maze.getCell(newRow, newCol) == 'E')
        {
            Maze2d endMaze = s.getState();
            endMaze.setCell(newRow, newCol, 'E');

            State<Maze2d> *endState = new State<Maze2d>(endMaze);
            endState->setCost(s.getCost() + 1);
            endState->setCameFrom(&s);
            possibleStates->push_back(endState);
            break;
        }
    }
}


        return possibleStates;
    }
};
