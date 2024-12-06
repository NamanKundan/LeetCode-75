#include <vector>
#include <numeric> // For accumulate function
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Calculating the total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Initializing left sum to 0
        int leftSum = 0;

        // Traversing the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Calculating the right sum as totalSum - leftSum - nums[i]
            int rightSum = totalSum - leftSum - nums[i];

            // If left sum equals right sum, the current index is the pivot
            if (leftSum == rightSum) {
                return i;
            }

            // Updating left sum by adding the current element
            leftSum += nums[i];
        }

        // If no pivot index is found, return -1
        return -1;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    // Calculating and printing the pivot index
    int result = solution.pivotIndex(nums);
    printf("The pivot index is: %d\n", result);

    return 0;
}
