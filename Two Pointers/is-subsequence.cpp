#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for string s
        int j = 0; // Pointer for string t

        // Traversing both strings
        while (i < s.length() && j < t.length()) {
            // If characters match, moving pointer for s
            if (s[i] == t[j]) {
                i++;
            }
            // Always move pointer for t
            j++;
        }

        // If i has reached the end of s, all characters in s were found in t
        return i == s.length();
    }
};

int main() {
    Solution solution;

    string s = "abc";
    string t = "ahbgdc";

    bool result = solution.isSubsequence(s, t);

    if (result) {
        cout << "\"" << s << "\" is a subsequence of \"" << t << "\"." << endl;
    } else {
        cout << "\"" << s << "\" is not a subsequence of \"" << t << "\"." << endl;
    }

    return 0;
}
