#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // This function is calculating the minimum speed at which Koko can eat all bananas within h hours
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  // Initializing the minimum possible speed
        int right = *max_element(piles.begin(), piles.end());  // Setting the maximum speed as the largest pile

        // Performing binary search to find the optimal speed
        while (left < right) {
            int mid = left + (right - left) / 2;  // Calculating the middle speed
            if (canEatAll(piles, h, mid)) {  
                right = mid;  // Updating the right boundary if Koko can finish in time
            } else {
                left = mid + 1;  // Increasing speed if Koko cannot finish in time
            }
        }
        return left;  // Returning the minimum speed required
    }

private:
    // This function is checking if Koko can eat all bananas at a given speed within h hours
    bool canEatAll(vector<int>& piles, int h, int k) {
        int hours = 0;  // Initializing the hours counter
        for (int pile : piles) {
            hours += (pile + k - 1) / k;  // Calculating the total hours needed at speed k
        }
        return hours <= h;  // Returning true if eating within h hours is possible
    }
};

// This is the main function for testing the solution
int main() {
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};  // Defining the banana piles
    int h = 8;  // Setting the number of available hours

    // Calling the function and displaying the minimum required eating speed
    cout << "Minimum eating speed: " << solution.minEatingSpeed(piles, h) << endl;
    return 0;
}