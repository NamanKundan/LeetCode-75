#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // Initializing two priority queues to track the smallest costs
        priority_queue<int, vector<int>, greater<int>> leftHeap;  // For the first 'candidates' workers
        priority_queue<int, vector<int>, greater<int>> rightHeap; // For the last 'candidates' workers

        // Initializing two pointers for workers selection
        int left = 0, right = costs.size() - 1;

        // Adding initial workers to the left and right heaps
        while (left < candidates && left <= right) {
            leftHeap.push(costs[left++]);
        }
        while (right >= costs.size() - candidates && left <= right) {
            rightHeap.push(costs[right--]);
        }

        long long totalCost = 0;

        // Hiring exactly k workers
        for (int i = 0; i < k; ++i) {
            // Determining which heap to choose from based on cost and index priority
            if (!rightHeap.empty() && (leftHeap.empty() || rightHeap.top() < leftHeap.top())) {
                totalCost += rightHeap.top();
                rightHeap.pop();
                // Adding new workers to the right heap if possible
                if (right >= left) {
                    rightHeap.push(costs[right--]);
                }
            } else {
                totalCost += leftHeap.top();
                leftHeap.pop();
                // Adding new workers to the left heap if possible
                if (left <= right) {
                    leftHeap.push(costs[left++]);
                }
            }
        }

        return totalCost; // Returning the total cost of hiring k workers
    }
};