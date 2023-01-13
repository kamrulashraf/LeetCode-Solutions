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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        makeTree(nums,root, 0, nums.size() - 1);
        
        return root;
    }
    
    void makeTree(vector<int>& nums, TreeNode* root, int b , int e){
        
        int m = (b+e)/2;
        root -> val = nums[m];
        
        
        
        if(b <= m-1){
            TreeNode* left = new TreeNode();
            root -> left = left;
            makeTree(nums, left, b, m-1);
        }
        
        if(m+1 <= e){
            TreeNode* right = new TreeNode();
            root->right = right;
            makeTree(nums,right,m+1,e);
        }
    }
};