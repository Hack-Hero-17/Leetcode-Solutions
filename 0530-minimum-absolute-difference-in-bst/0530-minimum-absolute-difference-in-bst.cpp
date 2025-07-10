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
    int getMinimumDifference(TreeNode* root) {
        int minimum = INT_MAX;
        int prev = INT_MAX;
        inorder( root , minimum , prev );
        return minimum;
    }
    void inorder( TreeNode * root , int & minimum ,int & prev){
        if( root == NULL )
            return;
        inorder( root->left , minimum , prev );
        
        if( prev != INT_MAX ){
            int temp = abs( prev - root->val );
            minimum = min ( minimum , temp );
        }
        prev = root->val;
        inorder( root->right, minimum, prev );
    }
};