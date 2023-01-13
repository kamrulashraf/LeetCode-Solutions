/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, TreeNode*> par;
        dfs(root, par);

        map<TreeNode*, bool> vis;

        while(p){
            vis[p] = true;
            p = par[p];
        }

        while(q){
            if(vis[q]){
                return q;
            }
            q = par[q];
        }

        return root;
    }

    void dfs(TreeNode* root, map<TreeNode*,TreeNode*> &par){

        if(root->left){
            par[root->left] = root;
            dfs(root->left, par);
        }

        
        if(root->right){
            par[root->right] = root;
            dfs(root->right, par);
        }

    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval, rval, qval;
        pval = p->val;
        qval = q->val;
        rval = root->val;

        if(pval < rval && qval < rval && root -> left)
            return lowestCommonAncestor(root -> left, p , q);
        else if(pval > rval && qval > rval && root -> right)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};