#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    // Defining the function to calculate successful pairs
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        // Sorting the potions array to perform binary search
        std::sort(potions.begin(), potions.end());
        
        std::vector<int> result; // To store the number of successful pairs for each spell
        
        // Iterating through each spell
        for (int spell : spells) {
            // Calculating the minimum potion strength required for success
            long long required = (success + spell - 1) / spell;

            // Finding the first potion that meets or exceeds the required strength using binary search
            auto it = std::lower_bound(potions.begin(), potions.end(), required);

            // Calculating the number of successful pairs
            int count = potions.end() - it;

            // Storing the count in the result array
            result.push_back(count);
        }

        // Returning the result array
        return result;
    }
};

// Main function to test the successfulPairs function
int main() {
    Solution solution;

    // Example test case
    std::vector<int> spells = {5, 1, 3};
    std::vector<int> potions = {1, 2, 3, 4, 5};
    int success = 7;

    // Getting the result
    std::vector<int> result = solution.successfulPairs(spells, potions, success);

    // Printing the result
    std::cout << "Successful pairs: ";
    for (int count : result) {
        std::cout << count << " ";
    }
    std::cout << std::endl;

    return 0;
}