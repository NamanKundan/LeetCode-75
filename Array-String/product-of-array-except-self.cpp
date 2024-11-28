#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Computing prefix product for each index
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Computing suffix product and multiply with the prefix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
