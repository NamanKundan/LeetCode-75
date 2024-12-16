#include <iostream>
using namespace std;

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
    int goodNodes(TreeNode* root) {
        // Calling the helper function to count good nodes starting from the root
        return countGoodNodes(root, INT_MIN);
    }

private:
    int countGoodNodes(TreeNode* node, int maxSoFar) {
        // Checking if the current node is null
        if (!node) 
            return 0;

        // Determining if the current node is good
        int count = (node->val >= maxSoFar) ? 1 : 0;

        // Updating the maximum value for the current path
        maxSoFar = max(maxSoFar, node->val);

        // Recursively counting good nodes in the left subtree
        count += countGoodNodes(node->left, maxSoFar);

        // Recursively counting good nodes in the right subtree
        count += countGoodNodes(node->right, maxSoFar);

        // Returning the total count of good nodes for this subtree
        return count;
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Number of good nodes: " << solution.goodNodes(root) << endl;

    return 0;
}
