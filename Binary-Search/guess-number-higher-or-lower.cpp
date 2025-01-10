#include <iostream>

// Predefined API, placeholder for the actual implementation
int guess(int num) {
    // Assume the picked number is 6 for demonstration purposes
    int pick = 6;
    if (num > pick) return -1;
    else if (num < pick) return 1;
    else return 0;
}

// Defining the Solution class
class Solution {
public:
    // Implementing the guessNumber function to find the number picked
    int guessNumber(int n) {
        // Initializing the range of possible numbers
        int low = 1, high = n;

        // Starting a loop to narrow down the range
        while (low <= high) {
            // Calculating the middle of the range to make a guess
            int mid = low + (high - low) / 2;

            // Calling the guess API to get feedback on the guess
            int result = guess(mid);

            // Checking if the guess is correct
            if (result == 0) 
                return mid; // Returning the correct guess

            // Adjusting the range if the picked number is smaller
            else if (result == -1) 
                high = mid - 1;

            // Adjusting the range if the picked number is larger
            else 
                low = mid + 1;
        }

        // Returning -1 if no number is found (should not occur based on problem statement)
        return -1;
    }
};

// Main function to test the guessNumber function
int main() {
    Solution solution;

    // Example test case
    int n = 10; // Upper bound of the range
    int result = solution.guessNumber(n);

    // Printing the result
    std::cout << "The picked number is: " << result << std::endl;

    return 0;
}