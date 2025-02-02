#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // This function is storing the mapping of digits to corresponding letters
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    // This function is returning all possible letter combinations for the given digits
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Returning empty if there are no digits
        vector<string> result;
        backtrack(digits, 0, "", result);  // Calling backtracking function
        return result;
    }

private:
    // This function is performing backtracking to generate all possible letter combinations
    void backtrack(const string& digits, int index, string current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);  // Adding the formed combination to the result
            return;
        }

        // Getting the possible letters for the current digit
        string letters = digitToLetters[digits[index]];
        for (char letter : letters) {
            backtrack(digits, index + 1, current + letter, result);  // Recursively calling for next digit
        }
    }
};

// This is the main function to test the solution
int main() {
    Solution solution;
    string digits = "23";  // Defining input digits

    // Calling the function and storing the result
    vector<string> result = solution.letterCombinations(digits);

    // Printing the results
    cout << "Possible letter combinations: ";
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}