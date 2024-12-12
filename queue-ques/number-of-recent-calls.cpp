#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
private:
    // Declaring a queue to store the timestamps of recent requests
    queue<int> requests;

public:
    // Initializing the RecentCounter object
    RecentCounter() {
        // Starting with an empty queue
    }

    // Adding a new request and returning the number of recent requests in the past 3000 milliseconds
    int ping(int t) {
        // Adding the current timestamp to the queue
        requests.push(t);

        // Removing timestamps that are older than t - 3000
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // Returning the size of the queue, which represents the count of recent requests
        return requests.size();
    }
};

// Main function to test the RecentCounter class
int main() {
    // Creating an object of RecentCounter
    RecentCounter recentCounter;

    // Test cases
    cout << "Ping at 1: " << recentCounter.ping(1) << endl;     // Output: 1
    cout << "Ping at 100: " << recentCounter.ping(100) << endl; // Output: 2
    cout << "Ping at 3001: " << recentCounter.ping(3001) << endl; // Output: 3
    cout << "Ping at 3002: " << recentCounter.ping(3002) << endl; // Output: 3

    return 0;
}
