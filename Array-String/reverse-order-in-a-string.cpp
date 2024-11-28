#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        // Extracting words while ignoring extra spaces
        while (ss >> word) {
            words.push_back(word);
        }

        // Reversing the order of the words
        reverse(words.begin(), words.end());

        // Joining the words with a single space
        string result = "";
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    string s = "   the sky is blue   ";
    cout << '"' << solution.reverseWords(s) << '"' << endl; // Output: "blue is sky the"
    return 0;
}
