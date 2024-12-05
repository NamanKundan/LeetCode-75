#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int zeroCount = 0; // Keeps track of the number of zeros in the window
        int maxLength = 0;

        while (right < nums.size()) {
            // Expanding the window by including nums[right]
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrinking the window if there are more than 1 zero
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Updating the maximum length of the subarray
            // Subtracting 1 because we must remove one element
            maxLength = max(maxLength, right - left);

            right++;
        }

        return maxLength;
    }
};

// Main function for testing
int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 1, 0, 1};

    // Calculating the result
    int result = solution.longestSubarray(nums);

    // Output the result
    printf("Longest subarray of 1's after deleting one element: %d\n", result);

    return 0;
}
