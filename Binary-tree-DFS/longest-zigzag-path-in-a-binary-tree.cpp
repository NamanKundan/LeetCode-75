#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    // Declaring a variable to store the longest ZigZag path
    int maxLength = 0;

    // Function to calculate the longest ZigZag path
    int longestZigZag(TreeNode* root) {
        // Starting recursive exploration from the root node
        dfs(root, true, 0); // Starting with direction as left
        dfs(root, false, 0); // Starting with direction as right
        // Returning the maximum length found
        return maxLength;
    }

private:
    // Recursive function to perform a depth-first search
    void dfs(TreeNode* node, bool isLeft, int currentLength) {
        // Checking if the current node is null
        if (!node) return;

        // Updating the maximum length if the current length is greater
        maxLength = max(maxLength, currentLength);

        // Exploring the next node based on the current direction
        if (isLeft) {
            // If moving left, incrementing length and switching direction to right
            dfs(node->left, false, currentLength + 1);
            // Resetting length and switching direction to left
            dfs(node->right, true, 1);
        } else {
            // If moving right, incrementing length and switching direction to left
            dfs(node->right, true, currentLength + 1);
            // Resetting length and switching direction to right
            dfs(node->left, false, 1);
        }
    }
};

// Example usage
int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->left->right->right = new TreeNode(1);

    // Creating a solution object
    Solution solution;

    // Finding and printing the longest ZigZag path
    cout << "Longest ZigZag Path: " << solution.longestZigZag(root) << endl;

    return 0;
}
