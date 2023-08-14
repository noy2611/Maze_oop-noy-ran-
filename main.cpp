#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include "myModal.h"
#include "Maze2d.h"
#include "myMaze2dGenerator.h"
#include "playMaze2d.h"
#include "myView.h"

#include <iostream>
#include <fstream> // Include the necessary header for file streams
using namespace std;

int main()
{

   // Default values
   int m = 2, n = 2;
   int x = 0, y = 0;
   string name;
   cout << "Random Maze Generator!" << endl;
   cout << "Enter the Height  the width and the name of the maze: ";
   cin >> x >> y >> name;
   while (x < 1 || y < 1)
   {
      cout << "Desired dimensions impossible. Re-enter pls." << endl;
      cin >> x >> y >> name;
   }
   // Calculate the number of rows in the maze
   int M = 2 * m + 1;
   // Calculate the number of columns in the maze
   int N = 2 * n + 1;

   int X = 2 * x + 1;
   int Y = 2 * y + 1;

   /////////////////////////////////////////test/////////////////////////////////////////

   //  Maze2d maze1;
   // Generate maze
   myMaze2dGenerator generator;

   // Generate the maze using the generator
   // cout<<maze.getCell(0,0)<<endl;
   // cout<< maze.getCellIndex(1,1)<<endl;
   //    MazeManager man;
   // man.saveMaze("test",maze,M,N);
   // man.printMaze("test");
   // maze = generator.generate(M, N, maze);

   // maze.setCell(0, 1, 'S');
   // maze.setCell(2 * m, 2 * n - 1, 'E');
   // maze.display();
   MazeManager man;
   Maze2d maze;
   Maze2d maze2(X, Y, name);
   maze2 = generator.generate(X, Y, maze2);
   maze2.setCell(0, 1, 'S');
   maze2.setCell(2 * x, 2 * y - 1, 'E');
   maze2.display();
 //man.saveMazeToFile(maze.getName(),maze);


   Maze2d maze1(M, N, "ran");
   maze1.setCell(0, 1, 'S');
   maze1.setCell(2 * m, 2 * n - 1, 'E');
   maze1 = generator.generate(M, N, maze1);

   string filePath, filePath2;
   cout << "Enter name" << endl;
   cin >> filePath;
   man.loadFile(filePath, maze);

   maze1.setCell(0, 1, 'S');
   maze1.setCell(2 * m, 2 * n - 1, 'E');

   man.addMazeData(maze.getName(), maze);
   man.addMazeData(maze1.getName(), maze1);
   man.addMazeData(maze2.getName(), maze2);

   man.getMaze(maze2.getName()).display();
   man.getMaze(maze.getName()).display();
   man.getMaze(maze1.getName()).display();
displayFilesAndFolders(filePath);
   // string filePath = "noy1.txt";

   // size_t fileSize = man.calculateFileSize(filePath);
   //   maze1.display();

  Maze2d maze;
  
    man.loadFile(filePath, maze);
   
    maze.display();
    maze.calculateMemorySize();
    cout<<maze.getSize();
   //  cout << maze.getName();
   // cout<<"the size of maze is"<<endl;
   // man.displaySizeInFile(filePath,fileSize);

   // man.saveMazeToFile(maze.getName(),maze);
   // man.loadMazeFromFile(,maze);
   //   man.loadMazeFromFile("noy1");
   //  playMaze2d player;
   // player.InitializePlayableMaze(maze);
   // player.Play();
   return 0;
}