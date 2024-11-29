#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // Position to write the compressed characters
        int read = 0;  // Position to read the characters

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Counting the occurrences of the current character
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Writting the character to the array
            chars[write++] = currentChar;

            // If the count is greater than 1, write the count
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};

int main() {
    Solution solution;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = solution.compress(chars);

    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}
