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
    int kthSmallest(TreeNode* root, int k) {
        int value;
        inorder( root , k , value);
        return value;
    }
    void inorder( TreeNode * root , int& k , int & value){
        if( root == NULL )
            return;
        inorder( root->left , k, value );
        k--;
        if( k==0 )
            value = root->val;
        inorder( root->right , k, value );
    }
};