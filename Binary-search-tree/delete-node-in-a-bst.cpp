#include <iostream>

using namespace std;

// Definition of the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive in-order traversal function
void printInOrder(TreeNode* node) {
    if (!node) return;           // Returning if the node is NULL
    printInOrder(node->left);    // Traversing the left subtree
    cout << node->val << " ";    // Printing the current node's value
    printInOrder(node->right);   // Traversing the right subtree
}

// Main function to test in-order traversal
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "In-Order Traversal (Using Recursive Function): ";
    printInOrder(root); // Calling the recursive function
    cout << endl;

    return 0;
}
