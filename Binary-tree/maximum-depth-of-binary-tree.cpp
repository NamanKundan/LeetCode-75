#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Checking if the root is null, returning 0 in such case
        if (root == nullptr) {
            return 0;
        }
        // Recursively calculating the maximum depth of the left subtree
        int leftDepth = maxDepth(root->left);
        // Recursively calculating the maximum depth of the right subtree
        int rightDepth = maxDepth(root->right);
        // Returning the maximum depth by taking the greater value between left and right, and adding 1 for the current node
        return max(leftDepth, rightDepth) + 1;
    }
};

// Main function to test the solution
int main() {
    // Creating a binary tree: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.maxDepth(root);

    // Printing the result
    cout << "Maximum Depth of Binary Tree: " << result << endl;

    return 0;
}
