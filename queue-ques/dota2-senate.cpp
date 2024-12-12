#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        // Declaring two queues to hold the indices of Radiant and Dire senators
        queue<int> radiantQueue, direQueue;

        // Iterating through the input string to populate the queues
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                // Adding Radiant senator's index to the queue
                radiantQueue.push(i);
            } else {
                // Adding Dire senator's index to the queue
                direQueue.push(i);
            }
        }

        // Processing the rounds until one queue becomes empty
        while (!radiantQueue.empty() && !direQueue.empty()) {
            // Fetching the indices of the first senators in both queues
            int radiantIndex = radiantQueue.front();
            radiantQueue.pop();
            int direIndex = direQueue.front();
            direQueue.pop();

            // Comparing the indices to decide who bans whom
            if (radiantIndex < direIndex) {
                // Adding the Radiant senator back to the queue after banning a Dire senator
                radiantQueue.push(radiantIndex + senate.size());
            } else {
                // Adding the Dire senator back to the queue after banning a Radiant senator
                direQueue.push(direIndex + senate.size());
            }
        }

        // Returning the party that still has senators left
        return radiantQueue.empty() ? "Dire" : "Radiant";
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    
    // Example input
    string senate = "RD";
    
    // Calling the function and printing the result
    string result = solution.predictPartyVictory(senate);
    cout << "Winning Party: " << result << endl;
    
    return 0;
}
