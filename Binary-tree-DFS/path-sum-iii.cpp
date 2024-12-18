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
    // Function to calculate the number of paths with a given target sum
    int pathSum(TreeNode* root, int targetSum) {
        // If the root is null, return 0
        if (!root) return 0;

        // Returning the paths starting from the root node
        // and including the left and right subtrees
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

private:
    // Helper function to find paths using depth-first search
    int dfs(TreeNode* node, long long currentSum) {
        // If the current node is null, return 0
        if (!node) return 0;

        // Reducing the target sum by the current node's value
        currentSum -= node->val;

        // Checking if the current path matches the target sum
        // and recursively searching the left and right subtrees
        return (currentSum == 0 ? 1 : 0) + dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};

// Example usage
int main() {
    // Constructing a sample binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    // Target sum
    int targetSum = 8;

    // Creating a solution instance and calculating the result
    Solution solution;
    int result = solution.pathSum(root, targetSum);

    // Printing the result
    cout << "Number of paths with sum " << targetSum << ": " << result << endl;

    return 0;
}
