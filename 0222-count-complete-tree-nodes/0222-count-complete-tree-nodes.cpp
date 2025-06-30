/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = 0;
        int right = 0;
        left = leftH(root->left);
        right = rightH(root->right);
        if (left == right)
            return (1 << (left + 1)) - 1;
        else {
            int l, r;
            l = countNodes(root->left);
            r = countNodes(root->right);
            return l + r + 1;
        }
    }
    int leftH(TreeNode* root) {
        if (root == NULL)
            return 0;
        return leftH(root->left) + 1;
    }
    int rightH(TreeNode* root) {
        if (root == NULL)
            return 0;
        return rightH(root->right) + 1;
    }
};