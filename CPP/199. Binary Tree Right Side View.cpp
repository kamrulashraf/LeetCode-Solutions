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
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root){
            return vector<int> {};
        }
        TreeNode *cur = root;
        vector<int> ret;
        queue<TreeNode*> q;
        map<TreeNode*,int> level;
        map<int,int> levelCounter;
        
        q.push(root);
        level[root] = 1;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            int count = ++levelCounter[level[top]];
            if(count == 1){
                ret.push_back(top->val);
            }
            
            if(top->right){
                q.push(top -> right);
                level[top->right] = level[top] + 1;            
            }
            
            if(top->left){
                q.push(top-> left);
                level[top->left] = level[top] + 1;            
            }
            
        }
        
        return ret;
    }
};