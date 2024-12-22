#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // Initializing the directions for movement: up, down, left, right.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Creating a queue for BFS and pushing the entrance coordinates along with the initial step count (0).
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        // Marking the entrance cell as visited by converting it to a wall.
        maze[entrance[0]][entrance[1]] = '+';
        
        // Starting BFS traversal.
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();
                
                // Checking if the current cell is a valid exit (not the entrance and on the border).
                if ((row == 0 || row == maze.size() - 1 || col == 0 || col == maze[0].size() - 1) &&
                    !(row == entrance[0] && col == entrance[1])) {
                    return steps;
                }
                
                // Exploring all four possible directions.
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;

                    // Checking if the new cell is within bounds and is an empty cell.
                    if (newRow >= 0 && newRow < maze.size() && newCol >= 0 && newCol < maze[0].size() && 
                        maze[newRow][newCol] == '.') {
                        // Marking the cell as visited by converting it to a wall.
                        maze[newRow][newCol] = '+';
                        // Adding the new cell to the queue for further exploration.
                        q.push({newRow, newCol});
                    }
                }
            }
            // Incrementing the step count after processing all cells at the current level.
            ++steps;
        }
        
        // Returning -1 if no exit is found.
        return -1;
    }
};
