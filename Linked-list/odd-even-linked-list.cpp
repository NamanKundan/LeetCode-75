// Including necessary headers
#include <iostream>
using namespace std;

// Defining the structure of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Checking if the list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }

        // Initializing pointers for odd and even indexed nodes
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        // Traversing the list to rearrange nodes
        while (even && even->next) {
            // Updating the next pointer of odd nodes
            odd->next = even->next;
            odd = odd->next;

            // Updating the next pointer of even nodes
            even->next = odd->next;
            even = even->next;
        }

        // Connecting the end of the odd-indexed list to the head of the even-indexed list
        odd->next = evenHead;

        // Returning the modified list
        return head;
    }
};

// Function to print a linked list
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
    // Creating an example linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating a Solution object
    Solution solution;

    // Calling the function to rearrange the list
    ListNode* result = solution.oddEvenList(head);

    // Printing the modified list
    printList(result);

    return 0;
}
