#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;              // Pointer at the beginning
        int right = height.size() - 1; // Pointer at the end
        int maxArea = 0;           // To store the maximum area

        // Using the two-pointer technique
        while (left < right) {
            // Calculating the area with the current pointers
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;

            // Updating maxArea if the current area is larger
            maxArea = max(maxArea, area);

            // Moving the pointer pointing to the smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = solution.maxArea(height);

    cout << "Maximum area of water the container can store: " << result << endl;

    return 0;
}
