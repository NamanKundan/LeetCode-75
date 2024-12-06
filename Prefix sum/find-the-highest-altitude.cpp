#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (int g : gain) {
            currentAltitude += g;
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> gain = {-5, 1, 5, 0, -7};

    // Calculate and output the result
    int result = solution.largestAltitude(gain);
    printf("The highest altitude is: %d\n", result);

    return 0;
}
