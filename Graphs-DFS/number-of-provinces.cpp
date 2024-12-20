#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the total number of provinces
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Storing the number of cities
        vector<bool> visited(n, false); // Initializing a visited array to track visited cities
        int provinceCount = 0; // Initializing the count of provinces

        // Iterating through all cities
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // Checking if the city is not visited
                provinceCount++; // Incrementing the province count
                bfs(isConnected, visited, i); // Performing BFS to visit all connected cities
            }
        }
        return provinceCount; // Returning the total number of provinces
    }

private:
    // Function to perform BFS and visit all cities in a province
    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int start) {
        queue<int> q; // Initializing a queue for BFS
        q.push(start); // Adding the starting city to the queue
        visited[start] = true; // Marking the starting city as visited

        while (!q.empty()) { // Running BFS until the queue is empty
            int city = q.front(); // Getting the current city
            q.pop(); // Removing it from the queue

            // Iterating through all cities to find connected cities
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[city][j] == 1 && !visited[j]) { // Checking if the city is connected and not visited
                    q.push(j); // Adding the connected city to the queue
                    visited[j] = true; // Marking the connected city as visited
                }
            }
        }
    }
};

int main() {
    Solution solution; // Creating an instance of the Solution class
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}; // Input adjacency matrix
    int result = solution.findCircleNum(isConnected); // Finding the number of provinces
    cout << "Number of provinces: " << result << endl; // Printing the result
    return 0;
}
