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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if( root == NULL )
            return result;

        queue<TreeNode *> NodeQueue;
        NodeQueue.push( root );
        
        while( !NodeQueue.empty() ){

            int size = NodeQueue.size();

            double sum = 0;

            for( int i=0 ; i<size ; i++ ){
                TreeNode * node = NodeQueue.front();
                NodeQueue.pop();
                sum += node->val; 
                if( node->left )
                    NodeQueue.push( node->left );
                if( node->right )   
                    NodeQueue.push( node->right );
            }
            sum = sum/size;
            result.push_back( sum );
        }
        return result;
    }
};