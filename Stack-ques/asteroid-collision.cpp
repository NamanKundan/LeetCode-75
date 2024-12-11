#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Declaring a stack to hold the final state of the asteroids
        vector<int> stack;

        // Iterating through each asteroid in the input array
        for (int asteroid : asteroids) {
            // Processing the current asteroid
            bool isDestroyed = false;

            // Handling collisions when the current asteroid is moving left
            while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                // Comparing the sizes of the colliding asteroids
                if (abs(stack.back()) < abs(asteroid)) {
                    // Popping the smaller asteroid from the stack as it is exploding
                    stack.pop_back();
                } else if (abs(stack.back()) == abs(asteroid)) {
                    // Popping both asteroids as they are of the same size and are exploding
                    stack.pop_back();
                    isDestroyed = true;
                    break;
                } else {
                    // Marking the current asteroid as destroyed as the stack asteroid is larger
                    isDestroyed = true;
                    break;
                }
            }

            // Adding the current asteroid to the stack if it is not destroyed
            if (!isDestroyed) {
                stack.push_back(asteroid);
            }
        }

        // Returning the final state of the asteroids
        return stack;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    
    // Defining example input
    vector<int> asteroids = {5, 10, -5};
    
    // Calling the function and storing the result
    vector<int> result = solution.asteroidCollision(asteroids);
    
    // Printing the result
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
