#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0; // Returning 0 when n is 0
        if (n == 1 || n == 2) return 1; // Returning 1 when n is 1 or 2

        int t0 = 0, t1 = 1, t2 = 1, t3;
        for (int i = 3; i <= n; i++) {
            t3 = t0 + t1 + t2; // Calculating the current Tribonacci number
            t0 = t1; // Updating t0 to the next value
            t1 = t2; // Updating t1 to the next value
            t2 = t3; // Updating t2 to the next value
        }
        return t3; // Returning the nth Tribonacci number
    }
};

int main() {
    Solution sol;
    int n = 4; // Defining the input value
    cout << "Tribonacci of " << n << " is: " << sol.tribonacci(n) << endl; // Calling the function and printing the result
    return 0;
}