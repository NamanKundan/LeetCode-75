#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Initializing the left and right pointers for binary search
        int left = 0, right = nums.size() - 1;

        // Performing binary search to find a peak
        while (left < right) {
            // Calculating the middle index
            int mid = left + (right - left) / 2;

            // Checking if the middle element is smaller than its next element
            if (nums[mid] < nums[mid + 1]) {
                // Moving the left pointer to the right of mid
                left = mid + 1;
            } else {
                // Moving the right pointer to the middle
                right = mid;
            }
        }

        // Returning the index of the peak element
        return left;
    }
};