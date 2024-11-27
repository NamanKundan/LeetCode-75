#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();

        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                // Checking if the adjacent plots are empty or if i is at the boundary
                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    // Planting a flower here
                    flowerbed[i] = 1;
                    count++;
                    // Skiping the next plot as adjacent planting is not allowed
                    i++;
                }
            }

            // Early exiting if enough flowers have been planted
            if (count >= n) {
                return true;
            }
        }

        return count >= n;
    }
};

int main() {
    Solution solution;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    cout << (solution.canPlaceFlowers(flowerbed, n) ? "true" : "false") << endl;

    return 0;
}
