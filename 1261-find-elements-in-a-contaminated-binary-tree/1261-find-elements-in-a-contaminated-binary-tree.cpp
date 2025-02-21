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
class FindElements {
private:
    unordered_set<int> values; // Store all recovered values

    // Helper function to recover the tree
    void recoverTree(TreeNode* node, int value) {
        if (!node)
            return;
        node->val = value;
        values.insert(value);
        recoverTree(node->left, 2 * value + 1);
        recoverTree(node->right, 2 * value + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root) {
            recoverTree(root, 0);
        }
    }

    bool find(int target) { return values.count(target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */