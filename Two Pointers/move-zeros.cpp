#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroIndex = 0; // Indexing to place the next non-zero element

        // Moving non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }

        // Filling the remaining positions with zeros
        for (int i = nonZeroIndex; i < n; i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    
    solution.moveZeroes(nums);

    cout << "Modified array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
