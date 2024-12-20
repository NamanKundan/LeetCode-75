#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Initializing a set to keep track of visited rooms
        unordered_set<int> visited;

        // Initializing a queue to manage the rooms to be visited
        queue<int> toVisit;

        // Starting with room 0 since it's always unlocked
        toVisit.push(0);
        visited.insert(0);

        // Performing a BFS to visit all rooms
        while (!toVisit.empty()) {
            // Retrieving the next room from the queue
            int currentRoom = toVisit.front();
            toVisit.pop();

            // Iterating over all keys found in the current room
            for (int key : rooms[currentRoom]) {
                // Checking if the room corresponding to the key is not yet visited
                if (visited.find(key) == visited.end()) {
                    // Marking the room as visited
                    visited.insert(key);
                    // Adding the room to the queue for future exploration
                    toVisit.push(key);
                }
            }
        }

        // Checking if the number of visited rooms equals the total number of rooms
        return visited.size() == rooms.size();
    }
};

int main() {
    // Defining a sample input: rooms with their keys
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};

    // Creating an instance of the Solution class
    Solution solution;

    // Calling the canVisitAllRooms function and storing the result
    bool result = solution.canVisitAllRooms(rooms);

    // Printing the result
    cout << (result ? "True" : "False") << endl;

    return 0;
}
