#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Initializing the sum of the first window
        double maxSum = 0, currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }
        maxSum = currentSum;

        // Sliding the window
        for (int i = k; i < nums.size(); i++) {
            currentSum += nums[i] - nums[i - k]; // Updating the sum for the new window
            maxSum = max(maxSum, currentSum);   // Updating maxSum if the new sum is greater
        }

        return maxSum / k; // Returning the maximum average
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    // Creating an instance of the solution and call the function
    Solution solution;
    double result = solution.findMaxAverage(nums, k);

    // Output the result
    cout << "Maximum average: " << result << endl;

    return 0;
}
