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
    bool isSymmetric(TreeNode* root) {
        return isSubTreeValid(root -> left , root -> right);
    }
    
    bool isSubTreeValid(TreeNode *a, TreeNode *b){
        if(a == NULL && b == NULL){
            return true;
        }
        
        if((a == NULL && b != NULL) || (a != NULL && b == NULL)){
            return false;
        }
        if(a -> val != b -> val){
            return false;
        }
        
        return isSubTreeValid(a -> left, b -> right) && isSubTreeValid(a -> right , b -> left);
    }
};