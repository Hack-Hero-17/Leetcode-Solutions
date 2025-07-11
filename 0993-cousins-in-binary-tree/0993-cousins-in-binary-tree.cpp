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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root->left || !root->right) return false;

        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,NULL});

        while(!q.empty()){
            int N=q.size();
            TreeNode* parentX=NULL;
            TreeNode* parentY=NULL;
            while(N--){
                TreeNode* currNode=q.front().first;
                TreeNode* parentNode=q.front().second;
                q.pop();

                if(currNode->val==x) parentX=parentNode;
                if(currNode->val==y) parentY=parentNode;

                if(currNode->left) q.push({currNode->left,currNode});
                if(currNode->right) q.push({currNode->right,currNode});
            }
            if(parentX && parentY) return parentX!=parentY;
            if(parentX || parentY) return false;
        }
        return false;
    }
};