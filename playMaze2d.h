#pragma once
#include "Maze2d.h"
#include <cstdlib>
#include <conio.h>
#define ANSI_COLOR_GREEN "\033[32m"
#define ANSI_COLOR_RESET "\033[0m"
using namespace std;

class playMaze2d
{
private:
    int numRows;
    int numCols;
    char **playableMaze;
    int playerRow;
    int playerCol;

public:
    playMaze2d() : numRows(0), numCols(0), playableMaze(nullptr), playerRow(0), playerCol(1){};
    ~playMaze2d(){};
    void InitializePlayableMaze(const Maze2d &maze);
    void displayWithPlayer() const;
    void Play();
    // Getters for the player's position
    int getPlayerRow() const
    {
        return playerRow;
    }

    int getPlayerCol() const
    {
        return playerCol;
    }
};

void playMaze2d::InitializePlayableMaze(const Maze2d &maze)
{
    numCols = maze.getColumns();
    numRows = maze.getRows();
    playableMaze = new char *[maze.getRows()];
    for (int i = 0; i < maze.getRows(); i++)
    {
        playableMaze[i] = new char[maze.getColumns()];
        for (int j = 0; j < maze.getColumns(); j++)
        {
            playableMaze[i][j] = maze.getCell(i, j);
        }
    }
}

void playMaze2d::displayWithPlayer() const
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (i == playerRow && j == playerCol)
            {
                cout << ANSI_COLOR_GREEN << 'P' << ANSI_COLOR_RESET << " "; // Display player symbol
            }
            else
            {
                cout << playableMaze[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout<<"press up/down/left/right or use q to quit"<<endl;
}
void playMaze2d::Play()
{
    // Display the initial state of the playable maze
    displayWithPlayer();
    
    while (true)
    {
         int ch = _getch(); 

        // Check for quit
        if (ch == 'q')
        {
            cout << "Quitting the game." << endl;
            break;
        }

        int newRow = playerRow;
        int newCol = playerCol;

        // Update new row and column based on arrow key input
        if (ch == 72) // Up arrow key
        {
            newRow--;
        }
        else if (ch == 75) // Left arrow key
        {
            newCol--;
        }
        else if (ch == 80) // Down arrow key
        {
            newRow++;
        }
        else if (ch == 77) // Right arrow key
        {
            newCol++;
        }

        // Check if the new position is valid (not a wall)
        if (playableMaze[newRow][newCol] == ' ' || playableMaze[newRow][newCol] == 'E')
        {   // Check for win condition
            if (playableMaze[newRow][newCol] == 'E') // Check if player reached the exit
            {
                cout << "Congratulations! You've reached the exit!" << endl;
                break;
            }
            // Update the playable maze with the new player position
            playableMaze[playerRow][playerCol] = ' '; // Clear the previous position
            playerRow = newRow;
            playerCol = newCol;
            playableMaze[playerRow][playerCol] = 'P'; // Update the new position

            // Clear the screen and display the updated playable maze
            cout << "\033[2J\033[H"; // Clear the console 
            displayWithPlayer();
        }
    }
}