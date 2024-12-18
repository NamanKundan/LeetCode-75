#include <iostream>
#include <queue>
#include <climits>    // For INT_MIN

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
    int maxLevelSum(TreeNode* root) {
        // Initializing a queue to perform level-order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Initializing variables to track the maximum sum and its level
        int maxSum = INT_MIN;
        int maxLevel = 0;

        // Starting with level 0
        int currentLevel = 0;

        // Traversing the tree level by level
        while (!q.empty()) {
            // Moving to the next level
            currentLevel++;

            // Getting the number of nodes at the current level
            int levelSize = q.size();

            // Initializing the sum of the current level
            int levelSum = 0;

            // Iterating through all nodes at this level
            for (int i = 0; i < levelSize; i++) {
                // Getting the front node in the queue
                TreeNode* node = q.front();
                q.pop();

                // Adding the value of the current node to the level sum
                levelSum += node->val;

                // Adding the left child to the queue if it exists
                if (node->left) {
                    q.push(node->left);
                }

                // Adding the right child to the queue if it exists
                if (node->right) {
                    q.push(node->right);
                }
            }

            // Checking if the current level sum is greater than the maximum sum so far
            if (levelSum > maxSum) {
                // Updating the maximum sum and its corresponding level
                maxSum = levelSum;
                maxLevel = currentLevel;
            }
        }

        // Returning the level with the maximum sum
        return maxLevel;
    }
};

// Helper function to create a binary tree for testing
TreeNode* createTree() {
    // Manually creating the tree in the example
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    return root;
}

int main() {
    // Creating the binary tree
    TreeNode* root = createTree();

    // Creating an object of the Solution class
    Solution solution;

    // Calculating the level with the maximum sum
    int result = solution.maxLevelSum(root);

    // Printing the result
    cout << "The level with the maximum sum is: " << result << endl;

    // Freeing the allocated memory (optional, for larger trees consider proper deletion)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
