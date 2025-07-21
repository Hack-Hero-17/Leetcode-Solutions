/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0; // \U0001f9f1 Base: null node
        
        if (!root->left) return minDepth(root->right) + 1; // ➡️ Only right child
        if (!root->right) return minDepth(root->left) + 1; // ⬅️ Only left child
        
        return min(minDepth(root->left), minDepth(root->right)) + 1; // \U0001f504 Take the shorter path
    }
};