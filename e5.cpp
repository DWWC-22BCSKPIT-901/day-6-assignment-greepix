#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int sumOfNodes(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int totalSum = 0;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            totalSum += node->val; // Add the current node value

            if (node->left) q.push(node->left); // Add left child
            if (node->right) q.push(node->right); // Add right child
        }

        return totalSum;
    }
};
int main() {
    // Construct the tree: [1, 2, 3, 4, 5, null, 6]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    cout << "Sum of All Nodes: " << sol.sumOfNodes(root) << endl; // Output: 21

    return 0;
}

