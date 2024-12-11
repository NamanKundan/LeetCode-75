#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution { 
public:
    string decodeString(string s) {
        // Declaring a stack to store repeat counts
        stack<int> countStack;
        // Declaring a stack to store string segments
        stack<string> stringStack;
        // Initializing the current working string
        string currentString = "";
        // Initializing the repeat count
        int k = 0;

        // Iterating over each character in the string
        for (char c : s) {
            // Checking if the current character is a digit
            if (isdigit(c)) {
                // Updating the repeat count by building the number
                k = k * 10 + (c - '0');
            }
            // Checking if the current character is an opening bracket
            else if (c == '[') {
                // Pushing the repeat count onto the stack
                countStack.push(k);
                // Pushing the current string onto the stack
                stringStack.push(currentString);
                // Resetting the current string for the next segment
                currentString = "";
                // Resetting the repeat count
                k = 0;
            }
            // Checking if the current character is a closing bracket
            else if (c == ']') {
                // Retrieving the previous string segment
                string decodedString = stringStack.top();
                stringStack.pop();
                // Retrieving the repeat count for this segment
                int currentK = countStack.top();
                countStack.pop();
                // Repeating the current string and appending it to the previous segment
                for (int i = 0; i < currentK; i++) {
                    decodedString += currentString;
                }
                // Updating the current string with the decoded result
                currentString = decodedString;
            }
            // If the character is part of the string (not a digit or bracket)
            else {
                // Adding the character to the current string
                currentString += c;
            }
        }

        // Returning the fully decoded string
        return currentString;
    }
};

// Main function to test the decodeString function
int main() {
    Solution solution;
    
    // Test case 1
    string input1 = "3[a]2[bc]";
    cout << "Input: " << input1 << endl;
    cout << "Decoded String: " << solution.decodeString(input1) << endl;

    // Test case 2
    string input2 = "3[a2[c]]";
    cout << "Input: " << input2 << endl;
    cout << "Decoded String: " << solution.decodeString(input2) << endl;

    // Test case 3
    string input3 = "2[abc]3[cd]ef";
    cout << "Input: " << input3 << endl;
    cout << "Decoded String: " << solution.decodeString(input3) << endl;

    return 0;
}
