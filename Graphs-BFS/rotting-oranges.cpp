#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Initializing variables to track rows and columns in the grid.
        int rows = grid.size();
        int cols = grid[0].size();

        // Using a queue to process rotten oranges and their influence over time.
        queue<pair<int, int>> q;

        // Variable to count the number of fresh oranges.
        int freshCount = 0;

        // Iterating over the grid to initialize the queue with all rotten oranges
        // and counting the total number of fresh oranges.
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }

        // If there are no fresh oranges, we return 0 as no time is needed.
        if (freshCount == 0) return 0;

        // Defining the directions for 4-directional movement.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Variable to track the time elapsed.
        int minutes = 0;

        // Performing BFS to rot all reachable fresh oranges.
        while (!q.empty()) {
            int size = q.size();
            bool hasNewRotten = false;

            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();

                // Checking all 4-directional neighbors.
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;

                    // If the neighboring cell is a fresh orange, it rots.
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2; // Rotting the orange.
                        q.push({newRow, newCol});
                        --freshCount; // Reducing the count of fresh oranges.
                        hasNewRotten = true;
                    }
                }
            }

            // If at least one orange rots in this round, we increase the time.
            if (hasNewRotten) ++minutes;
        }

        // If there are still fresh oranges left, return -1. Otherwise, return the elapsed time.
        return freshCount == 0 ? minutes : -1;
    }
};