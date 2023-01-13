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
    
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
       unordered_map <long,int> sumflag;
        calculatePath(root, targetSum, sumflag, 0);
        
        return res;
    }
    
    void calculatePath(TreeNode* root, int targetSum, unordered_map<long,int>& sumflag, long sum){
        if(!root)
            return;
        
        sum += root->val;
        long temp = sum - targetSum;
        res += sumflag[temp];
        if(sum == targetSum)
            res++;
        sumflag[sum]++;
        
        if(root -> left)
            calculatePath(root -> left, targetSum, sumflag, sum);
        
        if(root-> right)
            calculatePath(root-> right, targetSum ,sumflag, sum);
        
        sumflag[sum]--;
    }
};