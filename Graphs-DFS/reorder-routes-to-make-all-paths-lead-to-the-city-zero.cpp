#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Initializing adjacency lists for roads and reverse roads
        unordered_map<int, vector<int>> roads, reverseRoads;
        
        // Building adjacency lists for roads and reverse roads
        for (const auto& connection : connections) {
            roads[connection[0]].push_back(connection[1]); // Storing directed road
            reverseRoads[connection[1]].push_back(connection[0]); // Storing reverse direction
        }
        
        // Initializing a queue for BFS
        queue<int> q;
        q.push(0); // Starting BFS from city 0
        
        // Initializing a set to keep track of visited cities
        unordered_set<int> visited;
        visited.insert(0); // Marking city 0 as visited
        
        // Counter to track the number of edges to be reoriented
        int changes = 0;
        
        // Performing BFS to traverse all cities
        while (!q.empty()) {
            int city = q.front();
            q.pop();
            
            // Checking outgoing roads from the current city
            for (int nextCity : roads[city]) {
                if (visited.find(nextCity) == visited.end()) { // If not visited
                    changes++; // Incrementing the counter as this road needs reorientation
                    q.push(nextCity); // Adding the city to the queue
                    visited.insert(nextCity); // Marking it as visited
                }
            }
            
            // Checking reverse roads leading to the current city
            for (int prevCity : reverseRoads[city]) {
                if (visited.find(prevCity) == visited.end()) { // If not visited
                    q.push(prevCity); // Adding the city to the queue
                    visited.insert(prevCity); // Marking it as visited
                }
            }
        }
        
        return changes; // Returning the minimum number of edges to be reoriented
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    
    // Calling the function and printing the result
    cout << "Minimum edges to be reoriented: " << solution.minReorder(n, connections) << endl;
    return 0;
}
