class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int value;
        inorder(root, k, value);
        return value;
    }

    void inorder(TreeNode* root, int& k, int& value) {
        if (!root) return;

        inorder(root->left, k, value);

        k--; // Decrement k after visiting a node
        if (k == 0) {
            value = root->val;
            return;
        }

        inorder(root->right, k, value);
    }
};
