class Solution {

private:
    int preorderIndex;
    unordered_map<int, int> mapping;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mapping[rootVal];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }    
};