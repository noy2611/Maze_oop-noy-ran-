// #include <iostream>
// #include "State.h"
// #include "Searcher.h"
// #include "BFS.h"
// #include "EightPuzzelSearchableT.h"


// using namespace std;


// int main()
// {
// 	/*State a("A");
// 	State b("B");
// 	State goal("B");

// 	if(b == goal)
// 		cout << "Target State found!" << endl;*/


// 	EightPuzzel ep;
// 	EightPuzzelSearchableT ep_searchable(ep);

	
// 	/*Create Search algorithm*/
// 	Searcher<string>* search_BFS = new BFS<string>();
// 	Solution<string> solution = search_BFS->search(ep_searchable);

	
// 	ep_searchable.getGoalState();
// 	ep_searchable.getStartState();
// 	ep_searchable.getAllPossibleStates(*ep_searchable.getStartState());



// 	cin.get();
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>

// class Maze {
// private:
//     int width, height;
//     std::vector<std::vector<char>> grid;

// public:
//     Maze(int w, int h) : width(w), height(h) {
//         grid.resize(height, std::vector<char>(width, '#'));
//     }

//     void generate() {
//         srand(time(nullptr));  // Seed the random number generator

//         for (int i = 1; i < height - 1; i += 2) {
//             for (int j = 1; j < width - 1; j += 2) {
//                 grid[i][j] = ' ';
                
//                 if (i > 1) grid[i - 1][j] = ' ';  // Carve upward
//                 if (j > 1) grid[i][j - 1] = ' ';  // Carve left
//             }
//         }
//     }

//     void display() {
//         for (int i = 0; i < height; ++i) {
//             for (int j = 0; j < width; ++j) {
//                 std::cout << grid[i][j];
//             }
//             std::cout << '\n';
//         }
//     }
// };

// int main() {
//     int width = 21;  // Adjust the width and height as needed
//     int height = 21;

//     Maze maze(width, height);
//     maze.generate();
//     maze.display();

//     return 0;
// }
