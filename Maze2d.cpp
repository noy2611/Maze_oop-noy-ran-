#include "Maze2d.h"

Maze2d::Maze2d(int numRows, int numColumns, string name) : rows(numRows), columns(numColumns), mazeName(name)
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
    // Set the value of the cell at coordinates (x, y)
    // Make sure to handle bounds checking
    maze[x][y] = value;
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
void Maze2d::display()
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
    rows=row;
}
void Maze2d::setColumns(int col)
{
    columns=col;
}
 void Maze2d::createMazeGrid() {
        maze = new char*[rows];
        for (int i = 0; i < rows; ++i) {
            maze[i] = new char[columns];
        }
    }
