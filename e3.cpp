#include <iostream>
#include <algorithm> // For max function
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // Base case: null node has depth 0
        // Calculate depths of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // Return the maximum of the two depths + 1 for the current node
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    // Construct the tree: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Depth: " << sol.maxDepth(root) << endl; // Output: 3

    return 0;
}

