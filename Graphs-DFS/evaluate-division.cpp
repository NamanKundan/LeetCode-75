#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Creating a graph to store the relationships and weights
        unordered_map<string, vector<pair<string, double>>> graph;

        // Populating the graph with the equations and their respective values
        for (int i = 0; i < equations.size(); ++i) {
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            double value = values[i];
            graph[numerator].push_back({denominator, value});
            graph[denominator].push_back({numerator, 1.0 / value});
        }

        // Function to perform BFS and calculate the result for a single query
        auto bfs = [&](const string& src, const string& dest) -> double {
            if (graph.find(src) == graph.end() || graph.find(dest) == graph.end()) {
                // If either variable is not present in the graph, returning -1.0
                return -1.0;
            }
            if (src == dest) {
                // If both variables are the same, returning 1.0
                return 1.0;
            }
            // Initializing a queue for BFS
            queue<pair<string, double>> q;
            q.push({src, 1.0});
            // Maintaining a set to track visited nodes
            set<string> visited;
            visited.insert(src);

            // Processing the queue until empty
            while (!q.empty()) {
                auto [current, product] = q.front();
                q.pop();

                // Checking each neighbor of the current node
                for (const auto& [neighbor, value] : graph[current]) {
                    if (neighbor == dest) {
                        // If the destination is found, returning the computed product
                        return product * value;
                    }
                    if (visited.find(neighbor) == visited.end()) {
                        // If the neighbor is not visited, adding it to the queue
                        visited.insert(neighbor);
                        q.push({neighbor, product * value});
                    }
                }
            }
            // Returning -1.0 if no path exists between the variables
            return -1.0;
        };

        // Vector to store the results of all queries
        vector<double> results;
        for (const auto& query : queries) {
            // Calculating the result for each query using BFS
            results.push_back(bfs(query[0], query[1]));
        }
        // Returning the results
        return results;
    }
};