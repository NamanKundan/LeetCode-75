#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Checking if the current node is null or matches one of the target nodes
        if (!root || root == p || root == q) {
            // Returning the current node as it is either null or a match
            return root;
        }

        // Recursively searching in the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // Recursively searching in the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Checking if both left and right subtrees contain one of the nodes
        if (left && right) {
            // Returning the current node as it is the LCA
            return root;
        }

        // Returning either the left or right subtree if one contains both nodes
        return left ? left : right;
    }
};

// Main function for testing
int main() {
    // Creating a test binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;
    TreeNode* p = root->left;        // Node with value 5
    TreeNode* q = root->right;       // Node with value 1

    // Finding the LCA
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    // Printing the result
    cout << "The LCA of nodes " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
