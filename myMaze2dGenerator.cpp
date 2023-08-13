#include "myMaze2dGenerator.h"
Maze2d myMaze2dGenerator::generate(int M, int N, Maze2d maze)
{
    int m = (M / 2);
    int n = (N / 2);
    // Vector to store information about each cell
    vector<pair<int, pair<int, int>>> cell_list;//issue

    // Vector to keep track of visited cells
    vector<bool> visited(m * n, false);

    // Stack to store cells during maze generation
    stack<pair<int, pair<int, int>>> m_stack;//issue

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
    while (nVisited < (m * n)) 
    {
        
        vector<int> neighbours;
        // Check if there is a neighbor in the North direction 
        
        if (m_stack.top().second.first > 1)
        {   
            // Check if the cell above the current cell is not a wall (#) and hasn't been visited
            if (maze.getCell(m_stack.top().second.first - 2, m_stack.top().second.second + 0) &&
                !visited[maze.getCellIndex(m_stack.top().second.first - 2, m_stack.top().second.second + 0,cell_list)])
            {
                // If conditions are met, add the North neighbor direction (0) to the list of available neighbors
                
                neighbours.push_back(0);
            }
        }
        // East
        if (m_stack.top().second.second < N - 2)
        {   if (maze.getCell(m_stack.top().second.first + 0, m_stack.top().second.second + 2) &&
                !visited[maze.getCellIndex(m_stack.top().second.first + 0, m_stack.top().second.second + 2,cell_list)])
            {
                neighbours.push_back(1);
            }
        }
        // South
        if (m_stack.top().second.first < M - 2)
        {   if (maze.getCell(m_stack.top().second.first + 2, m_stack.top().second.second + 0) &&
                !visited[maze.getCellIndex(m_stack.top().second.first + 2, m_stack.top().second.second + 0,cell_list)])
            {
                neighbours.push_back(2);
            }
        }
        // West
        if (m_stack.top().second.second > 1)
        {  if (maze.getCell(m_stack.top().second.first + 0, m_stack.top().second.second - 2) &&
                !visited[maze.getCellIndex(m_stack.top().second.first + 0, m_stack.top().second.second - 2,cell_list)])
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
                maze.setCell(m_stack.top().second.first - 1, m_stack.top().second.second + 0, ' ');
                // Push the index of the chosen neighbor cell onto the stack
                m_stack.push(cell_list[maze.getCellIndex(m_stack.top().second.first - 2, m_stack.top().second.second + 0,cell_list)]);
                break;
            case 1: // East
            
                maze.setCell(m_stack.top().second.first + 0, m_stack.top().second.second + 1, ' ');
                m_stack.push(cell_list[maze.getCellIndex(m_stack.top().second.first + 0, m_stack.top().second.second + 2,cell_list)]);
                break;
            case 2: // South
           
                maze.setCell(m_stack.top().second.first + 1, m_stack.top().second.second + 0, ' ');
                m_stack.push(cell_list[maze.getCellIndex(m_stack.top().second.first + 2, m_stack.top().second.second + 0,cell_list)]);
                break;
            case 3: // West
                
                maze.setCell(m_stack.top().second.first + 0, m_stack.top().second.second - 1, ' ');
                m_stack.push(cell_list[maze.getCellIndex(m_stack.top().second.first + 0, m_stack.top().second.second - 2,cell_list)]);
                break;
            }
            // Mark the current cell as visited and increment the visited count
            visited[m_stack.top().first] = true;
            nVisited++;
        }
        else if (!m_stack.empty())
        {
            // If no available neighbors, backtrack by popping the current cell from the stack
            m_stack.pop();
        }
    }
    return maze;
}