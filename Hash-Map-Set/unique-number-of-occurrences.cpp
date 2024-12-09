#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        unordered_set<int> freqSet;

        // Counting occurrences of each element
        for (int num : arr) {
            freqMap[num]++;
        }

        // Checking if all frequencies are unique
        for (const auto& entry : freqMap) {
            if (freqSet.find(entry.second) != freqSet.end()) {
                return false;
            }
            freqSet.insert(entry.second);
        }

        return true;
    }
};
