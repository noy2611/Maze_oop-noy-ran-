#include "Maze2d.h"

Maze2d::Maze2d(int numRows, int numColumns, string name) : rows(numRows), columns(numColumns), mazeName(name), currentRow(0), currentCol(1)
{

    // Allocate memory for an array of character pointers (rows) for the maze
    maze = new char *[rows];
    // Allocate memory for each row of the maze
    for (int i = 0; i < rows; i++)
    {
        // Allocate memory for each column of the maze within the current row
        maze[i] = new char[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        // Loop through each column of the maze
        for (int j = 0; j < columns; j++)
        {
            // Check if either the row index 'i' or column index 'j' is even
            if (!(i & 1) || !(j & 1))
                // If either index is even, set the cell as a wall ('#')
                maze[i][j] = '#';
            else
                // If neither index is even, set the cell as an empty path (' ')
                maze[i][j] = ' ';
        }
    }
}
// Inside Maze2d.cpp
// Implement the copy constructor
Maze2d::Maze2d(const Maze2d &other)
    : rows(other.rows), columns(other.columns), mazeName(other.mazeName), currentRow(0), currentCol(1)
{
    // Allocate memory for the maze array
    maze = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        maze[i] = new char[columns];
    }

    // Copy the contents of the maze array from the other instance
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            maze[i][j] = other.maze[i][j];
        }
    }
}

Maze2d::~Maze2d()
{
}

int Maze2d::getRows() const
{
    return rows;
}

int Maze2d::getColumns() const
{
    return columns;
}

void Maze2d::setCell(int x, int y, char value)
{
    // Check if the provided coordinates are within valid bounds
    if (x >= 0 && x < rows && y >= 0 && y < columns)
    {
        // Set the value of the cell at coordinates (x, y)
        maze[x][y] = value;
    }
    else
    {
        // Coordinates are out of bounds, handle accordingly (e.g., throw an exception)
        // You can choose to log an error or take any other appropriate action
        std::cerr << "Error: Coordinates (" << x << ", " << y << ") are out of bounds." << std::endl;
        // You might choose to throw an exception here
    }
}

char Maze2d::getCell(int x, int y) const
{
    // Get the value of the cell at coordinates (x, y)
    // Make sure to handle bounds checking
    if (x >= 0 && x < rows && y >= 0 && y < columns)
    {
        return maze[x][y];
    }
    // Return a default value if coordinates are out of bounds
    return ' ';
}
int Maze2d::getSize() const
{
    return size;
}

string Maze2d::getName() const
{
    return mazeName;
}

void Maze2d::setName(const string &name)
{
    mazeName = name;
}
int Maze2d::getCellIndex(int row, int col, const vector<pair<int, pair<int, int>>> &cell_list) const
{
    // Convert 2D coordinates to a single index
    for (int i = 0; i < cell_list.size(); i++)
    {
        if (cell_list[i].second.first == row && cell_list[i].second.second == col)
            return cell_list[i].first;
    }
    // Return -1 if the index couldn't be found
    cout << "getCellIndex() couldn't find the index!" << endl;
    return -1;
}
void Maze2d::display() const
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
void Maze2d::setRows(int row)
{
    rows = row;
}
void Maze2d::setColumns(int col)
{
    columns = col;
}
void Maze2d::createMazeGrid()
{
    maze = new char *[rows];
    for (int i = 0; i < rows; ++i)
    {
        maze[i] = new char[columns];
    }
}
void Maze2d::calculateMemorySize()
{
    // Calculate size of mazeName and vector cell_list
    size = sizeof(mazeName);

    // Calculate size of 2D dynamic array maze
    for (int i = 0; i < rows; i++)
    {
        size += columns * sizeof(char); // Calculate size of each row
    }
    size += rows * sizeof(char *); // Calculate size of the array of row pointers
}
bool Maze2d::isValidMove(const Maze2d &currentState, int newRow, int newCol) const
{
    // std::cout << "Checking move to: " << newRow << ", " << newCol << std::endl;

    if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= columns)
    {
        // std::cout << "Move out of bounds." << std::endl;
        return false;
    }

    if (maze[newRow][newCol] == '#' || maze[newRow][newCol] == 'S')
    {
        // std::cout << "Move into a wall." << std::endl;
        return false;
    }

    // std::cout << "Valid move." << std::endl;
    return true;
}

pair<int, int> Maze2d::getGoalPosition() const
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            if (maze[row][col] == 'E')
            {
                return make_pair(row, col); // Return the position (row, col) of the goal state
            }
        }
    }
    // Return an invalid position if the goal state is not found
    return make_pair(-1, -1);
}
int Maze2d::getCurrentRow() const
{
    return currentRow;
}

int Maze2d::getCurrentColumn() const
{
    return currentCol;
}
void Maze2d::setCurrentRow(int ROW) const
{
    currentRow = ROW;
}
void Maze2d::setCurrentColumn(int COL) const
{
    currentCol = COL;
}
// Add a method to update the current row and column
void Maze2d::setCurrentPosition(int newRow, int newCol)
{
    currentRow = newRow;
    currentCol = newCol;
}