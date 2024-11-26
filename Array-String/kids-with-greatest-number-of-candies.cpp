#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandies = *max_element(candies.begin(), candies.end());

        for (int candy : candies) {
            // Checking if the current kid can have the greatest number of candies
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
    
    // Printing the result
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << (result[i] ? "true" : "false");
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
