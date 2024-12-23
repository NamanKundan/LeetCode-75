#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Initializing a min-heap to store the k largest elements.
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Iterating through the array to process each element.
        for (int num : nums) {
            // Adding the current element to the heap.
            minHeap.push(num);

            // Maintaining the size of the heap to be k.
            if (minHeap.size() > k) {
                minHeap.pop(); // Removing the smallest element if the heap exceeds size k.
            }
        }

        // Returning the top element of the heap, which is the kth largest.
        return minHeap.top();
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = solution.findKthLargest(nums, k);

    // Printing the kth largest element.
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}