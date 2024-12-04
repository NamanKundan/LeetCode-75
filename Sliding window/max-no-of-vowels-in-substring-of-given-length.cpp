#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; // Set of vowels
        int maxCount = 0, currentCount = 0;

        // Counting vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                currentCount++;
            }
        }
        maxCount = currentCount;

        // Sliding the window across the string
        for (int i = k; i < s.size(); i++) {
            if (vowels.count(s[i])) {
                currentCount++; // Adding the vowel at the end of the window
            }
            if (vowels.count(s[i - k])) {
                currentCount--; // Removing the vowel at the start of the window
            }
            maxCount = max(maxCount, currentCount); // Updating the max count
        }

        return maxCount;
    }
};

int main() {
    // Example input
    string s = "abciiidef";
    int k = 3;

    // Creating an instance of the solution and call the function
    Solution solution;
    int result = solution.maxVowels(s, k);

    // Output the result
    cout << "Maximum number of vowels in any substring of length " << k << ": " << result << endl;

    return 0;
}
