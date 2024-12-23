#include <set>
using namespace std;

// Defining the SmallestInfiniteSet class
class SmallestInfiniteSet {
private:
    set<int> numbers; // Using a set to maintain unique elements in sorted order
    int next;         // Tracking the next smallest number to add to the set if needed

public:
    // Constructor to initialize the set with all positive integers starting from 1
    SmallestInfiniteSet() {
        next = 1;
    }

    // Removing and returning the smallest integer from the set
    int popSmallest() {
        if (!numbers.empty()) {
            // Fetching the smallest element in the set
            int smallest = *numbers.begin();
            numbers.erase(numbers.begin()); // Removing it from the set
            return smallest;
        }
        // Returning and incrementing the next smallest number
        return next++;
    }

    // Adding a number back into the set if it's not already present
    void addBack(int num) {
        if (num < next) {
            numbers.insert(num); // Adding only if it is smaller than the current `next`
        }
    }
};

/*
Example Usage:

SmallestInfiniteSet smallestInfiniteSet = SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // Adding 2 back to the set
smallestInfiniteSet.popSmallest(); // Returns 1 and removes it
smallestInfiniteSet.popSmallest(); // Returns 2 and removes it
smallestInfiniteSet.popSmallest(); // Returns 3 and removes it
smallestInfiniteSet.addBack(1);    // Adding 1 back to the set
smallestInfiniteSet.popSmallest(); // Returns 1 and removes it
smallestInfiniteSet.popSmallest(); // Returns 4 and removes it
smallestInfiniteSet.popSmallest(); // Returns 5 and removes it
*/
