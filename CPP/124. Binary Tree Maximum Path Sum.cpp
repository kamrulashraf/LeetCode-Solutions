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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        subTreeMax(root, res);

        return res;
    }

    int subTreeMax(TreeNode *root, int &res){
        if(!root)
            return 0;

        int left = subTreeMax(root->left,res);
        int right = subTreeMax(root->right, res);

        left = max(0, left);  // not taking left side
        right = max(0,right); // not taking right side

        res = max(left+right + root->val, res);
        return max(left,right) + root-> val;
    }
};