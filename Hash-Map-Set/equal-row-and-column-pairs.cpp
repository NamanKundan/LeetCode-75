#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();  // Size of the matrix
        map<vector<int>, int> rowMap;  // Map to count the frequency of each row
        int count = 0;  // To store the number of equal row and column pairs

        // Step 1: Count the occurrences of each row in the grid
        for (int i = 0; i < n; i++) {
            rowMap[grid[i]]++;
        }

        // Step 2: Compare each column with the rows
        for (int j = 0; j < n; j++) {
            vector<int> col;  // To store the current column
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            // Add the count of this column from the rowMap
            count += rowMap[col];
        }

        return count;
    }
};

// Main function to demonstrate the solution
int main() {
    Solution solution;

    vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    cout << "Number of equal row and column pairs: " << solution.equalPairs(grid) << endl;

    return 0;
}
