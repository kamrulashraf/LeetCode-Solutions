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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        else
            return pathSum(root, targetSum);
    }
    
    bool pathSum(TreeNode* root, int targetSum){
        if(!root -> left && !root -> right && root->val == targetSum){
            return true;
        }
        
        
        bool left = false, right = false;
        
        if(root -> left)
            left = pathSum(root -> left , targetSum - root->val);
        
        if(root->right)
            right = pathSum(root -> right, targetSum - root->val);
        
        return left|right;
    }
};