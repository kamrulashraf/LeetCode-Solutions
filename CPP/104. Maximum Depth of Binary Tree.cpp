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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int ret1 = 0, ret2 = 0;
        if(root -> left != NULL){
            ret1 = 1 + maxDepth(root -> left);
        }
        if(root -> right != NULL){
            ret2 = 1 + maxDepth(root -> right);
        }
        
        return max(ret1 , max(ret2, 1));
    }
};