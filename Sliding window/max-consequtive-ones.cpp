#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Initializing pointers for the sliding window
        int left = 0, right = 0;
        // Variable to keep track of the count of zeros in the current window
        int zeroCount = 0;
        // Variable to store the maximum length of the subarray
        int maxLength = 0;

        // Iteratimg through the array with the `right` pointer
        while (right < nums.size()) {
            // If the current element is 0, increments the zero count
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If the zero count exceeds `k`, shrinks the window from the left
            while (zeroCount > k) {
                // If the element at the `left` pointer is 0, decrements the zero count
                if (nums[left] == 0) {
                    zeroCount--;
                }
                // Moving the left pointer to shrink the window
                left++;
            }

            // Updating the maximum length of the subarray
            maxLength = max(maxLength, right - left + 1);

            // Moving the right pointer to expand the window
            right++;
        }

        // Returning the maximum length found
        return maxLength;
    }
};

// Main function for testing
int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    // Calculating the result
    int result = solution.longestOnes(nums, k);

    // Output the result
    printf("Maximum number of consecutive 1's: %d\n", result);

    return 0;
}
