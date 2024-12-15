#include <vector>
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
    // This function is traversing the tree and collecting the leaf values
    void getLeafValues(TreeNode* root, vector<int>& leafValues) {
        if (!root) {
            return; // Exiting if the current node is null
        }
        if (!root->left && !root->right) {
            leafValues.push_back(root->val); // Adding leaf node value to the list
        }
        getLeafValues(root->left, leafValues); // Traversing the left subtree
        getLeafValues(root->right, leafValues); // Traversing the right subtree
    }

    // This function is checking if two trees are leaf-similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;

        // Collecting leaf values from the first tree
        getLeafValues(root1, leaves1);
        // Collecting leaf values from the second tree
        getLeafValues(root2, leaves2);

        // Comparing the two leaf value sequences
        return leaves1 == leaves2;
    }
};

// Example usage
int main() {
    // Creating the first tree
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);

    // Creating the second tree
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);

    Solution solution;
    bool result = solution.leafSimilar(root1, root2);

    // Printing the result
    if (result) {
        printf("The two trees are leaf-similar.\n");
    } else {
        printf("The two trees are not leaf-similar.\n");
    }

    return 0;
}
