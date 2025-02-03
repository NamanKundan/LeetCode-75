#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;  // Storing all valid combinations
        vector<int> combination;  // Storing the current combination
        backtrack(k, n, 1, combination, result);  // Calling the backtracking function
        return result;
    }

private:
    void backtrack(int k, int n, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (k == 0 && n == 0) {  // Checking if a valid combination is found
            result.push_back(combination);  // Adding the valid combination to result
            return;
        }
        if (k == 0 || n < 0) return;  // Stopping if the conditions are not met

        for (int i = start; i <= 9; i++) {  // Iterating through numbers 1 to 9
            combination.push_back(i);  // Adding the current number to combination
            backtrack(k - 1, n - i, i + 1, combination, result);  // Recursively calling with reduced k and n
            combination.pop_back();  // Removing the last added number to explore other possibilities
        }
    }
};

// Main function
int main() {
    Solution solution;
    int k = 3, n = 7;
    vector<vector<int>> result = solution.combinationSum3(k, n);

    cout << "Valid combinations: " << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); i++) {
            cout << combination[i] << (i < combination.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }
    return 0;
}
