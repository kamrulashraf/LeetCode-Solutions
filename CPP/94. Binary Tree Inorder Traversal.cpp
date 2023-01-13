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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ret, left, right;
        if(root == NULL){
            return ret;
        }
        if(root -> left != NULL){
            left = inorderTraversal(root -> left);
            ret.insert(ret.end(), left.begin(), left.end());
        }
        ret.push_back(root -> val);
        if(root -> right != NULL){
            right = inorderTraversal(root -> right);
            ret.insert(ret.end(), right.begin() , right.end());
        }
        return ret;
    }
};