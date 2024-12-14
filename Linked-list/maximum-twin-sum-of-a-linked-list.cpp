#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        // Declaring a vector to store the values of the linked list
        vector<int> values;

        // Iterating through the linked list and collecting values
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        // Initializing the maximum twin sum
        int maxSum = 0;

        // Iterating through the first half of the vector to calculate twin sums
        int n = values.size();
        for (int i = 0; i < n / 2; i++) {
            int twinSum = values[i] + values[n - 1 - i];
            maxSum = max(maxSum, twinSum); // Updating the maximum twin sum
        }

        // Returning the maximum twin sum
        return maxSum;
    }
};

// Example usage
int main() {
    // Creating a linked list [5,4,2,1]
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;
    int result = solution.pairSum(head);

    // Printing the result
    printf("Maximum Twin Sum: %d\n", result);

    return 0;
}
