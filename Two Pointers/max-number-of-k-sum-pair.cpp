#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To store the frequency of numbers
        int operations = 0;          // To count the number of operations

        for (int num : nums) {
            int complement = k - num; // Finding the required complement
            if (freq[complement] > 0) {
                // If the complement exists in the map, performing an operation
                operations++;
                freq[complement]--; // Decreasing its frequency
            } else {
                // Otherwise, increasing the frequency of the current number
                freq[num]++;
            }
        }

        return operations;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3, 4};
    int k = 5;

    int result = solution.maxOperations(nums, k);
    cout << "Maximum number of operations: " << result << endl;

    return 0;
}
