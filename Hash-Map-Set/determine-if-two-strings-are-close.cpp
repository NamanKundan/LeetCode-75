#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Step 1: Checking if the sizes of the strings are different
        // If they are, they can't be close
        if (word1.size() != word2.size()) {
            return false;
        }

        // Step 2: Creating frequency vectors for both strings
        vector<int> freq1(26, 0), freq2(26, 0);

        // Step 3: Creating sets to store unique characters in each string
        unordered_set<char> set1, set2;

        // Step 4: Filling frequency vector and character set for word1
        for (char c : word1) {
            freq1[c - 'a']++;
            set1.insert(c);
        }

        // Step 5: Filling frequency vector and character set for word2
        for (char c : word2) {
            freq2[c - 'a']++;
            set2.insert(c);
        }

        // Step 6: Sorting the frequency vectors
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Step 7: Checking if the sorted frequency vectors and sets match
        return freq1 == freq2 && set1 == set2;
    }
};

// Main function to demonstrate the solution
int main() {
    Solution solution;
    string word1 = "abc", word2 = "bca";

    // Calling the function and printing the result
    if (solution.closeStrings(word1, word2)) {
        cout << "The strings are close." << endl;
    } else {
        cout << "The strings are not close." << endl;
    }

    return 0;
}
