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
    mutable int currentRow;
    mutable int currentCol;

public:
    Maze2d(int numRows, int numColumns, string name);
    Maze2d(){};
    Maze2d(const Maze2d &other);
    ~Maze2d();
    // Set the value of a cell at coordinates (x, y)
    void setCell(int x, int y, char value);
    // Get the value of a cell at coordinates (x, y)
    char getCell(int x, int y) const;
    // Get the number of rows in the maze
    int getRows() const;
    void setRows(int row);
    // Get the number of columns in the maze
    int getColumns() const;
    void setColumns(int col);
    int getSize() const;              // Accessor for size
    string getName() const;           // Accessor for mazeName
    void setName(const string &name); // Mutator for mazeName
    int getCellIndex(int row, int col, const vector<pair<int, pair<int, int>>> &cell_list) const;
    void display() const;
    void createMazeGrid();
    void calculateMemorySize();
    bool isValidMove(const Maze2d &currentState, int newRow, int newCol) const;
    pair<int, int> getGoalPosition() const;
    int getCurrentRow() const;
    int getCurrentColumn() const;
    void setCurrentRow(int ROW)const;
    void setCurrentColumn(int COL)const;
    // Add a method to update the current row and column
    void setCurrentPosition(int newRow, int newCol);
    bool operator==(const Maze2d &other) const
    {
        // Compare the relevant members of Maze2d to determine equality
        // For example, you might compare rows, columns, mazeName, and maze contents
        return (rows == other.rows && columns == other.columns &&
                mazeName == other.mazeName && maze == other.maze);
    }
    bool operator<(const Maze2d &other) const
    {
        if (mazeName != other.mazeName)
            return mazeName < other.mazeName;
        if (rows != other.rows)
            return rows < other.rows;
        return columns < other.columns;
    }
};
