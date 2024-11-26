#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Checking if concatenation condition is valid
        if (str1 + str2 != str2 + str1) {
            return ""; // No common divisor
        }

        // Finding the GCD of lengths of str1 and str2
        int gcdLength = gcd(str1.size(), str2.size());
        
        // Returning the substring of length gcdLength from str1
        return str1.substr(0, gcdLength);
    }

private:
    // Helper function to calculate GCD of two integers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution solution;
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << "Largest string that divides both: " << solution.gcdOfStrings(str1, str2) << endl;
    return 0;
}
