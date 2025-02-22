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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;
        int i = 0;

        while (i < traversal.size()) {
            // Determine depth
            int depth = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Get node value
            int value = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            // Create new node
            TreeNode* node = new TreeNode(value);

            // Maintain stack: Pop elements if they are at the same or deeper depth
            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }

            // Attach the node to the correct parent
            if (!st.empty()) {
                TreeNode* parent = st.top().first;
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }

            // Push current node to stack
            st.push({node, depth});
        }

        // The root node is at the bottom of the stack
        while (st.size() > 1) {
            st.pop();
        }

        return st.top().first;
    }
};