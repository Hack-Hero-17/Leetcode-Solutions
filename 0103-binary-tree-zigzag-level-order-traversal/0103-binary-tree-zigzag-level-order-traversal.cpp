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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if( root == NULL )
            return result;

        bool leftToRight = true;

        queue<TreeNode *> node;
        node.push(root);
        while( !node.empty() ){
            int size = node.size();
            vector<int> row(size);
            for( int i=0 ; i< size ; i++ ){
                TreeNode * n = node.front();
                node.pop();

                int index = leftToRight ?  i : (size-1-i);
                row[index] = n->val;

                if( n->left )
                    node.push( n->left );
                if( n->right )
                    node.push( n->right );
            }

            leftToRight = !leftToRight;
            result.push_back( row );
        }
        return result;
    }
};