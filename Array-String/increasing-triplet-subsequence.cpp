#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                // Updating the smallest value
                first = num;
            } else if (num <= second) {
                // Updating the second smallest value
                second = num;
            } else {
                // Found a number greater than both first and second
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << (solution.increasingTriplet(nums) ? "true" : "false") << endl; // Output: true
    return 0;
}
