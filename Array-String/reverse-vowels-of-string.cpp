#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Moving left pointer until a vowel is found
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            // Moving right pointer until a vowel is found
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            // Swaping the vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

int main() {
    Solution solution;
    string s = "IceCreAm";
    cout << solution.reverseVowels(s) << endl; // Output: "AceCreIm"
    return 0;
}
