#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Checking if the list has only one node
        if (!head || !head->next) {
            // Returning null for a single-node list
            return nullptr;
        }

        // Initializing two pointers: slow and fast
        ListNode* slow = head;
        ListNode* fast = head;
        // Initializing a pointer to keep track of the node before the slow pointer
        ListNode* prev = nullptr;

        // Iterating through the list until the fast pointer reaches the end
        while (fast && fast->next) {
            // Moving the fast pointer two steps ahead
            fast = fast->next->next;
            // Updating the previous pointer to the current slow pointer
            prev = slow;
            // Moving the slow pointer one step ahead
            slow = slow->next;
        }

        // Skipping the middle node by updating the previous node's next pointer
        prev->next = slow->next;

        // Returning the modified list
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    // Creating a sample linked list: [1, 3, 4, 7, 1, 2, 6]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    // Deleting the middle node
    head = solution.deleteMiddle(head);

    cout << "Modified list: ";
    printList(head);

    return 0;
}
