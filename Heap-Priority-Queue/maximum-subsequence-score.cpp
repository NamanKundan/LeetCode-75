#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Defining the function to calculate the maximum score
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Creating a vector of pairs to hold values from both arrays
        vector<pair<int, int>> combined;
        
        // Combining nums1 and nums2 into a single vector of pairs
        for (int i = 0; i < nums1.size(); ++i) {
            combined.push_back({nums2[i], nums1[i]});
        }
        
        // Sorting the pairs by the values of nums2 in descending order
        sort(combined.rbegin(), combined.rend());
        
        // Using a min-heap (priority queue) to maintain the top-k largest elements from nums1
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, maxScore = 0;

        // Iterating over the sorted combined array
        for (const auto& [value2, value1] : combined) {
            // Adding the current nums1 value to the sum and the heap
            sum += value1;
            minHeap.push(value1);

            // If the heap size exceeds k, remove the smallest element to maintain size k
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // If the heap has exactly k elements, calculate the potential max score
            if (minHeap.size() == k) {
                maxScore = max(maxScore, sum * value2);
            }
        }

        // Returning the maximum score obtained
        return maxScore;
    }
};