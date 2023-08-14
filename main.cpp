#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include "myModal.h"
#include "Maze2d.h"
#include "myMaze2dGenerator.h"
#include "playMaze2d.h"

#include <iostream>
#include <fstream> // Include the necessary header for file streams
using namespace std;



int main()
{
   
   // Default values
   int m = 4, n = 4;
   string name;
   cout << "Random Maze Generator!" << endl;
   cout << "Enter the Height  the width and the name of the maze: ";
   cin >> m >> n >>name;
   while (m < 1 || n < 1)
   {
      cout << "Desired dimensions impossible. Re-enter pls." << endl;
      cin >> m >> n >> name;
   }
   //Calculate the number of rows in the maze
   int M = 2 * m + 1;
   // Calculate the number of columns in the maze
   int N = 2 * n + 1;

   /////////////////////////////////////////test/////////////////////////////////////////

   Maze2d maze(M, N,name);

    Maze2d maze1;
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

string filePath;
cout<<"Enter name"<<endl;
cin>>filePath;

// string filePath = "noy1.txt";
 man.loadAndProcessFile(filePath, maze1);  
    // size_t fileSize = man.calculateFileSize(filePath);
  maze1.display();


// cout<<"the size of maze is"<<endl;
 // man.displaySizeInFile(filePath,fileSize);




  // man.saveMazeToFile(maze.getName(),maze);
      // man.loadMazeFromFile(,maze);
   //   man.loadMazeFromFile("noy1");
    playMaze2d player;
   player.InitializePlayableMaze(maze);
   player.Play();
   return 0;
}