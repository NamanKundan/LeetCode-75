#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        // Initializing an empty string to act as a stack
        string result;

        // Iterating through each character in the input string
        for (char c : s) {
            if (c == '*') {
                // If the current character is a '*', removing the last character from the result
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                // If it's not a '*', add the character to the result
                result.push_back(c);
            }
        }

        // Returning the resulting string after processing all characters
        return result;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    
    // Example input
    string s = "leet**cod*e";
    
    // Calling the function and print the result
    string result = solution.removeStars(s);
    cout << "Output: " << result << endl;  // Expected Output: "lecoe"

    return 0;
}
