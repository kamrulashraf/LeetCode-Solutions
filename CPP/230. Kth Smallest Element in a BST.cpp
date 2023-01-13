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
    int kthSmallest(TreeNode* root, int k) {
        map<TreeNode*, int> count;
        getCount(root, count);    
        
        return getNumber(root,k,count);
    }
    
    int getNumber(TreeNode* root, int k, map<TreeNode*,int>&count){
        int left = 0, right = 0;
        if(root->left)
            left = count[root->left];
        
        if(root->right)
            right = count[root->right];
        
        if(left+1 == k){
            return root-> val;
        }
        else if(left >= k){
            return getNumber(root->left, k, count);
        }
        else{
            return getNumber(root->right, k- left-1, count);
        }
        
    }
    
    int getCount(TreeNode* root, map<TreeNode*, int>& count){
        if(!root)
            return 0;
        int left = 1 + getCount(root-> left, count);
        int right = getCount(root -> right, count);
        
        return count[root] = left + right;
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        getVal(root, k , res);
        return res;
    }

    int getVal(TreeNode * root, int k, int &res){
        if(res != -1)
            return res;
        if(!root)
            return 0;
        int right = 0;
        int left = getVal(root -> left, k, res);

        if(left + 1 == k){
            if(res == -1)
                res = root -> val;
        }
        else{
            right = getVal(root-> right, k-left-1, res);
        }

        return left + 1 + right;
    }
};