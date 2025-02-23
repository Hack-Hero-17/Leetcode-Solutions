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
    unordered_map<int, int> postIndex; // Store postorder index for fast lookup

    TreeNode* build(vector<int>& pre, int preStart, int preEnd, 
                    vector<int>& post, int postStart, int postEnd) {
        if (preStart > preEnd) return nullptr;
        TreeNode* root = new TreeNode(pre[preStart]);
        if (preStart == preEnd) return root; // Only one node

        int leftChild = pre[preStart + 1]; // Get left child
        int leftSize = postIndex[leftChild] - postStart + 1; // Size of left subtree

        root->left = build(pre, preStart + 1, preStart + leftSize, post, postStart, postStart + leftSize - 1);
        root->right = build(pre, preStart + leftSize + 1, preEnd, post, postStart + leftSize, postEnd - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++)
            postIndex[postorder[i]] = i; // Store postorder index for lookup

        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};