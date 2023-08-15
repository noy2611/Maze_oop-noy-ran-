#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include "myModal.h"
#include "Maze2d.h"
#include "myMaze2dGenerator.h"
#include "playMaze2d.h"
#include "myView.h"
#include "dircommand.h"
#include "mymaze2dGeneratorCommand.h"
#include "displaycommand.h"
#include "myController.h"
#include "saveCommend.h"
#include "loadcommand.h"
#include <iostream>
#include <fstream> // Include the necessary header for file streams
#include "BFS.h"
#include "SearchableAdapter.h"
#include "Cli.h"
#include "Maze2d.h"
#include "myMaze2dGenerator.h"
using namespace std;

// Default values
int m = 4, n = 4;
// Function to display the maze
void displayMaze(int M, int N, char **maze)
{
   for (int i = 0; i < M; i++)
   {
      for (int j = 0; j < N; j++)
      {
         cout << maze[i][j] << " ";
      }
      cout << endl;
   }
}

// Function to get the index of a cell from its coordinates
int getIdx(int x, int y, vector<pair<int, pair<int, int>>> cell_list)
{
   for (int i = 0; i < cell_list.size(); i++)
   {
      if (cell_list[i].second.first == x && cell_list[i].second.second == y)
         return cell_list[i].first;
   }
   cout << "getIdx() couldn't find the index!" << endl;
   return -1;
}
// Function to generate the maze using the depth-first search algorithm
void createMaze(int M, int N, char **maze)
{

   // Vector to store information about each cell
   vector<pair<int, pair<int, int>>> cell_list;

   // Vector to keep track of visited cells
   vector<bool> visited(m * n, false);

   // Stack to store cells during maze generation
   stack<pair<int, pair<int, int>>> m_stack;

   // Seed for random number generation
   random_device rdev;

   // Mersenne Twister random number generator using the seed
   mt19937 rng(rdev());

   // Distribution for generating random integers between 1 and 100
   uniform_int_distribution<mt19937::result_type> dist100(1, 100);

   int nVisited = 0;
   int k = 0;

   // Creating a list of cells with coordinates
   for (int i = 1; i < M; i += 2)
   {
      for (int j = 1; j < N; j += 2)
      {
         cell_list.push_back(make_pair(k, make_pair(i, j)));
         k++;
      }
   }
   // Initializing the maze generation with a random cell
   // Generate a random index within the range of cell_list
   int randIdx = dist100(rng) % (m * n);

   // Push the randomly chosen cell onto the stack
   m_stack.push(cell_list[randIdx]);

   // Mark the randomly chosen cell as visited
   visited[randIdx] = true;

   // Increment the count of visited cells
   nVisited++;

   // Maze generation algorithm
   while (nVisited < m * n)
   {

      vector<int> neighbours;
      // Check if there is a neighbor in the North direction
      if (m_stack.top().second.first > 1)
      {
         // Check if the cell above the current cell is not a wall (#) and hasn't been visited
         if (maze[m_stack.top().second.first - 2][m_stack.top().second.second + 0] &&
             !visited[getIdx(m_stack.top().second.first - 2, m_stack.top().second.second + 0, cell_list)])
         {
            // If conditions are met, add the North neighbor direction (0) to the list of available neighbors
            neighbours.push_back(0);
         }
      }
      // East
      if (m_stack.top().second.second < N - 2)
      {
         if (maze[m_stack.top().second.first + 0][m_stack.top().second.second + 2] &&
             !visited[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second + 2, cell_list)])
         {
            neighbours.push_back(1);
         }
      }
      // South
      if (m_stack.top().second.first < M - 2)
      {
         if (maze[m_stack.top().second.first + 2][m_stack.top().second.second + 0] &&
             !visited[getIdx(m_stack.top().second.first + 2, m_stack.top().second.second + 0, cell_list)])
         {
            neighbours.push_back(2);
         }
      }
      // West
      if (m_stack.top().second.second > 1)
      {
         if (maze[m_stack.top().second.first + 0][m_stack.top().second.second - 2] &&
             !visited[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second - 2, cell_list)])
         {
            neighbours.push_back(3);
         }
      }
      // Check if there are available neighbors to explore
      if (!neighbours.empty())
      {
         // Choose a random direction from the list of available neighbors
         int next_cell_dir = neighbours[dist100(rng) % neighbours.size()];
         // Create a path between this cell and neighbour
         switch (next_cell_dir)
         {
         case 0: // North
            // Carve a path from the current cell to the chosen neighbor (North direction)
            maze[m_stack.top().second.first - 1][m_stack.top().second.second + 0] = ' ';
            // Push the index of the chosen neighbor cell onto the stack
            m_stack.push(cell_list[getIdx(m_stack.top().second.first - 2, m_stack.top().second.second + 0, cell_list)]);
            break;
         case 1: // East
            maze[m_stack.top().second.first + 0][m_stack.top().second.second + 1] = ' ';
            m_stack.push(cell_list[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second + 2, cell_list)]);
            break;
         case 2: // South
            maze[m_stack.top().second.first + 1][m_stack.top().second.second + 0] = ' ';
            m_stack.push(cell_list[getIdx(m_stack.top().second.first + 2, m_stack.top().second.second + 0, cell_list)]);
            break;
         case 3: // West
            maze[m_stack.top().second.first + 0][m_stack.top().second.second - 1] = ' ';
            m_stack.push(cell_list[getIdx(m_stack.top().second.first + 0, m_stack.top().second.second - 2, cell_list)]);
            break;
         }
         // Mark the current cell as visited and increment the visited count
         visited[m_stack.top().first] = true;
         nVisited++;
      }
      else
      {
         // If no available neighbors, backtrack by popping the current cell from the stack
         m_stack.pop();
      }
   }
}

int main()
{

   // Default values
   // // int m = 2, n = 2;
   // // int x = 0, y = 0;
   // // string name;
   // // cout << "Random Maze Generator!" << endl;
   // // cout << "Enter the Height  the width and the name of the maze: ";
   // // cin >> x >> y >> name;
   // // while (x < 1 || y < 1)
   // // {
   // //    cout << "Desired dimensions impossible. Re-enter pls." << endl;
   // //    cin >> x >> y >> name;
   // // }
   // // Calculate the number of rows in the maze
   // // int M = 2 * m + 1;
   // // Calculate the number of columns in the maze
   // // int N = 2 * n + 1;

   // // int X = 2 * x + 1;
   // // int Y = 2 * y + 1;

   /////////////////////////////////////////test/////////////////////////////////////////

   //   Maze2d maze1;
   // Generate maze
   // // myMaze2dGenerator generator;

   // Generate the maze using the generator
   // cout<<maze.getCell(0,0)<<endl;
   // cout<< maze.getCellIndex(1,1)<<endl;
      //  MazeManager man;
   // man.saveMaze("test",maze,M,N);
   // man.printMaze("test");
   // maze = generator.generate(M, N, maze);

   // maze.setCell(0, 1, 'S');
   // maze.setCell(2 * m, 2 * n - 1, 'E');
   // maze.display();
   // // MazeManager man;
   // // Maze2d maze;
   // // Maze2d maze2(X, Y, name);
   // // maze2 = generator.generate(X, Y, maze2);
   // // maze2.setCell(0, 1, 'S');
   // // maze2.setCell(2 * x, 2 * y - 1, 'E');
   // // maze2.display();
   // man.saveMazeToFile(maze.getName(),maze);

   // Maze2d maze1(M, N, "ran");
   // maze1.setCell(0, 1, 'S');
   // maze1.setCell(2 * m, 2 * n - 1, 'E');
   // maze1 = generator.generate(M, N, maze1);

   // // string filePath, filePath2;
   // // cout << "Enter name" << endl;
   // // cin >> filePath;
   // // man.loadFile(filePath, maze);

   // maze1.setCell(0, 1, 'S');
   // maze1.setCell(2 * m, 2 * n - 1, 'E');

   // man.addMazeData(maze.getName(), maze);
   // man.addMazeData(maze1.getName(), maze1);
   // man.addMazeData(maze2.getName(), maze2);

   // man.getMaze(maze2.getName()).display();
   // man.getMaze(maze.getName()).display();
   // man.getMaze(maze1.getName()).display();
   // displayFilesAndFolders(filePath);
   // string filePath = "noy1.txt";

   // size_t fileSize = man.calculateFileSize(filePath);
   //   maze1.display();

   // //   Maze2d maze;

   //    //  man.loadFile("noy.txt", maze);

   //    //  maze.display();
   //    //  SearchableAdapter adapter(maze);

    // Instantiate the BFS searcher
   //  BFS<Maze2d> bfsSearcher;

    // Measure efficiency and print results
   //  bfsSearcher.checkEfficiency(adapter);
   //  maze.display();
   //  cout<<"test"<<endl;
   //  maze.display();
   //  maze.calculateMemorySize();
   //    //  cout<<maze.getSize();
   //  cout << maze.getName();
   // cout<<"the size of maze is"<<endl;
   // man.displaySizeInFile(filePath,fileSize);

   // man.saveMazeToFile(maze.getName(),maze);
   // man.loadMazeFromFile(,maze);
   //   man.loadMazeFromFile("noy1");
   //  playMaze2d player;
   // player.InitializePlayableMaze(maze);
   // player.Play();

   // displayFilesAndFolders(filePath);

   // בדיקה לdir command
   //  vector<string> path;
   //  string inputLine;

   // cout << "Enter a path: ";
   // getline(cin, inputLine);

   // // Split the input line into words
   // istringstream iss(inputLine);
   // string word;
   // while (iss >> word)
   // {
   //    path.push_back(word);
   // }

   // dircommand dir;
   // dir.execute(path);

   // generate maze command
   //  int M, N;
   //  mymaze2dGeneratorCommand generatorCommand;

   // std::cout << "Enter value of M: ";
   // std::cin >> M;
   // std::cout << "Enter value of N: ";
   // std::cin >> N;
   // string name;
   // std::cout << "Enter NAME: ";
   // std::cin >> name;

   // // // Prepare the command arguments
   //  std::vector<std::string> commandArgs = { std::to_string(M), std::to_string(N), name };

   // // // Call the execute function for maze generation
   //  generatorCommand.execute(commandArgs);

   // // Create a Maze2d instance to store the generated maze
   // Maze2d generatedMaze;
   // displaycommand dis;

   // dis.execute(commandArgs);
   // Cli check;
   // check.start();
   /// check
   // int M, N;
   // mymaze2dGeneratorCommand generatorCommand;

   // std::cout << "Enter value of M: ";
   // std::cin >> M;
   // std::cout << "Enter value of N: ";
   // std::cin >> N;
   // string name;
   // std::cout << "Enter NAME: ";
   // std::cin >> name;

   // Prepare the command arguments
   // std::vector<std::string> commandArgs = {std::to_string(M), std::to_string(N), name};
   // // Maze2d disp;
 
   // // Call the execute function for maze generation
   // generatorCommand.execute(commandArgs);


// displaycommand displayCommand;

//     // Prepare the display command arguments (maze name)


// saveCommend saveCommand;
//        vector<string> saveArgs = {"save", name}; // Assuming "save" is the command to save
//     saveCommand.execute(saveArgs);

// cout<<"load: "<<endl;
 loadcommand loadCommand;

//     // Prepare the command arguments (replace these with actual values)
  std::vector<std::string> commandArgs1 = {"load", "noy", "noy.txt"};

//     // Call the execute function for loading
    loadCommand.execute(commandArgs1);
   

    // loadcommand loadCmd;
    // vector<string> commandArgs1 = {"load", "noy1","noy1.txt"};
    // loadCmd.execute(commandArgs1);

//       std::vector<std::string> displayArgs = {"display", "noy"};

// //     // Call the execute function for displaying the maze
//     displayCommand.execute(displayArgs);

   return 0;
}