#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;                  // Value of the node
    TreeNode* left;           // Pointer to the left child
    TreeNode* right;          // Pointer to the right child
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Checking if the current node is null or its value matches the target
        if (root == NULL || root->val == val) {
            return root;
        }

        // Deciding whether to search in the left or right subtree
        if (val < root->val) {
            // Recursively searching in the left subtree if the value is smaller
            return searchBST(root->left, val);
        } else {
            // Recursively searching in the right subtree if the value is larger
            return searchBST(root->right, val);
        }
    }
};

// Helper function to create a binary search tree for testing
TreeNode* createTree() {
    // Manually creating the tree in the example
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    return root;
}

// Helper function to print the values in a subtree (in-order traversal)
void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Creating the binary search tree
    TreeNode* root = createTree();

    // Target value to search in the tree
    int val = 2;

    // Creating an object of the Solution class
    Solution solution;

    // Searching for the node with the given value
    TreeNode* result = solution.searchBST(root, val);

    // Printing the subtree rooted at the found node or indicating it doesn't exist
    if (result != NULL) {
        cout << "Subtree rooted at the node with value " << val << ": ";
        printTree(result);
        cout << endl;
    } else {
        cout << "Node with value " << val << " does not exist in the tree." << endl;
    }

    // Freeing the allocated memory (optional, for larger trees consider proper deletion)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
