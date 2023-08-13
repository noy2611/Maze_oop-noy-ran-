#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Maze2d
{
private:
    string mazeName;
    int rows;
    int columns;
    int size;
    // Declare a pointer to a pointer (2D array) of characters for the maze
    char **maze;
    vector<pair<int, pair<int, int>>> cell_list;

public:
    Maze2d(int numRows, int numColumns, string name);
    Maze2d(){};
    ~Maze2d();
  


    // Set the value of a cell at coordinates (x, y)
    void setCell(int x, int y, char value);

    // Get the value of a cell at coordinates (x, y)
    char getCell(int x, int y) const;

    // Get the number of rows in the maze
    int getRows() const;

    // Get the number of columns in the maze
    int getColumns() const;

    int getSize() const; // Accessor for size

    string getName() const;           // Accessor for mazeName
    void setName(const string &name); // Mutator for mazeName
    int getCellIndex(int row, int col, const vector<pair<int, pair<int, int>>> &cell_list) const;
    void display()
    {

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
};
