#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        // Declaring the result vector to store the visible nodes
        vector<int> result;

        // Checking if the tree is empty
        if (!root) {
            return result;
        }

        // Initializing a queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Iterating while there are nodes in the queue
        while (!q.empty()) {
            // Storing the size of the current level
            int levelSize = q.size();

            // Iterating through each node in the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                // Checking if it is the last node in the level
                if (i == levelSize - 1) {
                    result.push_back(currentNode->val);
                }

                // Adding left and right children to the queue if they exist
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
        }

        // Returning the list of visible nodes from the right side
        return result;
    }
};

// Main function to test the solution
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> visibleNodes = solution.rightSideView(root);

    cout << "Right side view of the binary tree: ";
    for (int val : visibleNodes) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
