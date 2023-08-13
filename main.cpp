#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include "myModal.h"
#include "Maze2d.h"
#include "myMaze2dGenerator.h"
using namespace std;

// Default values
int m = 4, n = 4;
// Function to display the maze
// void displayMaze(int M, int N, char **maze)
// {
//    for (int i = 0; i < M; i++)
//    {
//       for (int j = 0; j < N; j++)
//       {
//          cout << maze[i][j] << " ";
//       }
//       cout << endl;
//    }
// }

// // Function to get the index of a cell from its coordinates
// int getIdx(int x, int y, vector<pair<int, pair<int, int>>> cell_list)
// {
//    for (int i = 0; i < cell_list.size(); i++)
//    {
//       if (cell_list[i].second.first == x && cell_list[i].second.second == y)
//          return cell_list[i].first;
//    }
//    cout << "getIdx() couldn't find the index!" << endl;
//    return -1;
// }
// // Function to generate the maze using the depth-first search algorithm
// void createMaze(int M, int N, char **maze)
// {

//    // Vector to store information about each cell
//    vector<pair<int, pair<int, int>>> cell_list;

//    // Vector to keep track of visited cells
//    vector<bool> visited(m * n, false);

//    // Stack to store cells during maze generation
//    stack<pair<int, pair<int, int>>> m_stack;

//    // Seed for random number generation
//    random_device rdev;

//    // Mersenne Twister random number generator using the seed
//    mt19937 rng(rdev());

//    // Distribution for generating random integers between 1 and 100
//    uniform_int_distribution<mt19937::result_type> dist100(1, 100);

//    int nVisited = 0;
//    int k = 0;

//    // Creating a list of cells with coordinates
//    for (int i = 1; i < M; i += 2)
//    {
//       for (int j = 1; j < N; j += 2)
//       {
//          cell_list.push_back(make_pair(k, make_pair(i, j)));
//          k++;
//       }
//    }
//    // Initializing the maze generation with a random cell
//    // Generate a random index within the range of cell_list
//    int randIdx = dist100(rng) % (m * n);

//    // Push the randomly chosen cell onto the stack
//    m_stack.push(cell_list[randIdx]);

//    // Mark the randomly chosen cell as visited
//    visited[randIdx] = true;

//    // Increment the count of visited cells
//    nVisited++;

//    // Maze generation algorithm
//    while (nVisited < m * n)
//    {

//       vector<int> neighbours;
//       // Check if there is a neighbor in the North direction
//       if (m_stack.top().second.first > 1)
//       {
//          // Check if the cell above the current cell is not a wall (#) and hasn't been visited
//          if (maze[m_stack.top().second.first - 2][m_stack.top().second.second + 0] &&
//              !visited[getIdx(m_stack.top().second.first - 2, m_stack.top().second.second + 0, cell_list)])
//          {
//             // If conditions are met, add the North neighbor direction (0) to the list of available neighbors
//             neighbours.push_back(0);
//          }
//       }
//       // East
//       if (m_stack.top().second.second < N - 2)
//       {
//          if (maze[m_stack.top().second.first + 0][m_stack.top().second.second + 2] &&
//              !visited[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second + 2, cell_list)])
//          {
//             neighbours.push_back(1);
//          }
//       }
//       // South
//       if (m_stack.top().second.first < M - 2)
//       {
//          if (maze[m_stack.top().second.first + 2][m_stack.top().second.second + 0] &&
//              !visited[getIdx(m_stack.top().second.first + 2, m_stack.top().second.second + 0, cell_list)])
//          {
//             neighbours.push_back(2);
//          }
//       }
//       // West
//       if (m_stack.top().second.second > 1)
//       {
//          if (maze[m_stack.top().second.first + 0][m_stack.top().second.second - 2] &&
//              !visited[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second - 2, cell_list)])
//          {
//             neighbours.push_back(3);
//          }
//       }
//       // Check if there are available neighbors to explore
//       if (!neighbours.empty())
//       {
//          // Choose a random direction from the list of available neighbors
//          int next_cell_dir = neighbours[dist100(rng) % neighbours.size()];
//          // Create a path between this cell and neighbour
//          switch (next_cell_dir)
//          {
//          case 0: // North
//             // Carve a path from the current cell to the chosen neighbor (North direction)
//             maze[m_stack.top().second.first - 1][m_stack.top().second.second + 0] = ' ';
//             // Push the index of the chosen neighbor cell onto the stack
//             m_stack.push(cell_list[getIdx(m_stack.top().second.first - 2, m_stack.top().second.second + 0, cell_list)]);
//             break;
//          case 1: // East
//             maze[m_stack.top().second.first + 0][m_stack.top().second.second + 1] = ' ';
//             m_stack.push(cell_list[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second + 2, cell_list)]);
//             break;
//          case 2: // South
//             maze[m_stack.top().second.first + 1][m_stack.top().second.second + 0] = ' ';
//             m_stack.push(cell_list[getIdx(m_stack.top().second.first + 2, m_stack.top().second.second + 0, cell_list)]);
//             break;
//          case 3: // West
//             maze[m_stack.top().second.first + 0][m_stack.top().second.second - 1] = ' ';
//             m_stack.push(cell_list[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second - 2, cell_list)]);
//             break;
//          }
//          // Mark the current cell as visited and increment the visited count
//          visited[m_stack.top().first] = true;
//          nVisited++;
//       }
//       else
//       {
//          // If no available neighbors, backtrack by popping the current cell from the stack
//          m_stack.pop();
//       }
//    }
// }

int main()
{
   
   cout << "Random Maze Generator!" << endl;
   cout << "Enter the Height and the width of the maze: ";
   cin >> m >> n;
   while (m < 1 || n < 1)
   {
      cout << "Desired dimensions impossible. Re-enter pls." << endl;
      cin >> m >> n;
   }
   //Calculate the number of rows in the maze
   int M = 2 * m + 1;
   // Calculate the number of columns in the maze
   int N = 2 * n + 1;
   // Declare a pointer to a pointer (2D array) of characters for the maze
   // char **maze;
   // // Allocate memory for an array of character pointers (rows) for the maze
   // maze = new char *[M];

   // // Allocate memory for each row of the maze
   // for (int i = 0; i < M; i++)
   // {
   //    // Allocate memory for each column of the maze within the current row
   //    maze[i] = new char[N];
   // }

   // Initialize the maze grid with walls and paths
   // Loop through each row of the maze
   // for (int i = 0; i < M; i++)
   // {
   //    // Loop through each column of the maze
   //    for (int j = 0; j < N; j++)
   //    {
   //       // Check if either the row index 'i' or column index 'j' is even
   //       if (!(i & 1) || !(j & 1))
   //          // If either index is even, set the cell as a wall ('#')
   //          maze[i][j] = '#';
   //       else
   //          // If neither index is even, set the cell as an empty path (' ')
   //          maze[i][j] = ' ';
   //    }
   // }

   // createMaze(M, N, maze);
   // maze[0][1] = 'S';
   // maze[2 * m][2 * n - 1] = 'E';
   // cout << "Here's the maze you asked for. Enjoy! :D" << endl;
   // displayMaze(M, N, maze);

   /////////////////////////////////////////test/////////////////////////////////////////

   Maze2d maze(M, N);
   
   // Generate maze
    myMaze2dGenerator generator;

   // Generate the maze using the generator
   // cout<<maze.getCell(0,0)<<endl;
   // cout<< maze.getCellIndex(1,1)<<endl;
//    MazeManager man;
// man.saveMaze("test",maze,M,N);
// man.printMaze("test");
   maze = generator.generate(M, N, maze);
   
   MazeManager man;


   maze.setCell(0, 1, 'S');
   maze.setCell(2 * m, 2 * n - 1, 'E');
   maze.display();
      man.saveMazeToFile("myMaze",maze);
   return 0;
}