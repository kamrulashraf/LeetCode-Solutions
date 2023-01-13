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
    
    map< TreeNode*, int> minval;
    map< TreeNode*, int> maxval;
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        if(root == NULL) return true;
        TreeNode *left, *right;
        left = root -> left;
        right = root-> right;
        bool leftRet = isValidBST(left);
        bool rightRet = isValidBST(right);
        
        minval[root] = min(left?minval[left]:INT_MAX, right?minval[right]:INT_MAX);
        minval[root] = min(minval[root], root->val);
        
        maxval[root] = max(left?maxval[left]:INT_MIN, right?maxval[right]:INT_MIN);
        maxval[root] = max(root->val, maxval[root]);
        
        if(!leftRet || !rightRet){
            return false;
        }
        if(left && maxval[left] >= root->val)
            return false;
        
        if(right && minval[right] <= root->val){
            return false;
        }
        
        return true;
        
    }
};