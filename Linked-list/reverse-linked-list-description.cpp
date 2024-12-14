#include <iostream>
#include <vector>
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
    ListNode* reverseList(ListNode* head) {
        // Declaring a pointer for the previous node
        ListNode* prev = nullptr;
        // Initializing the current node to the head of the list
        ListNode* curr = head;

        // Iterating through the linked list
        while (curr != nullptr) {
            // Storing the next node temporarily
            ListNode* nextTemp = curr->next;
            // Reversing the link of the current node
            curr->next = prev;
            // Moving the previous pointer to the current node
            prev = curr;
            // Moving the current pointer to the next node
            curr = nextTemp;
        }
        // Returning the new head of the reversed list
        return prev;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Creating a linked list from input
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(input);

    // Printing the original linked list
    cout << "Original list: ";
    printLinkedList(head);

    // Reversing the linked list
    ListNode* reversedHead = solution.reverseList(head);

    // Printing the reversed linked list
    cout << "Reversed list: ";
    printLinkedList(reversedHead);

    return 0;
}
