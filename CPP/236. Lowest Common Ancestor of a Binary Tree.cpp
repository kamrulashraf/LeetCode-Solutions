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
    unordered_map <TreeNode*, TreeNode*> par;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root);
        
        map<TreeNode*,bool> vis;
        
        while( p != root){
            vis[p] = true;
            p = par[p];
        }
        
        while(q != root){
            if(vis[q])
                break;
            q = par[q];
        }
        
        return q;
    }
    
    void dfs(TreeNode* root){
        if(root->left){
            par[root->left] = root;
            dfs(root->left);            
        }
        if(root->right){
            par[root->right] = root;
            dfs(root->right);
        }
    }
};

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
    TreeNode* save = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root, p , q);
        return save;
    }
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(!root){
            return false;
        }
        if(save){
            return false;
        }
        
        
        int left = dfs(root->left,p,q);
        int right = dfs(root->right,p,q);
        
        int rootval = (p == root || q == root) ? 1 : 0;
        
        if(left + right + rootval >= 2 && !save){
            save = root;
        }
        
        
        return left  + right + rootval;
    }
};