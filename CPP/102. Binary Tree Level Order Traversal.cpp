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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        map<TreeNode*, int> level;
        vector<vector<int>> res;
        
        if(!root)
            return res;

        level[root] = 1;
        int maxlevel = 1;

        queue <TreeNode*> q;

        q.push(root);

        vector<int> temp;
        while(!q.empty()){
            TreeNode *top = q.front();
            int l = level[top];
            q.pop();
            if(l > maxlevel){
                maxlevel = l;
                res.push_back(temp);
                temp.clear();
            }

            temp.push_back(top->val);

            if(top -> left){
                q.push(top -> left);
                level[top->left] = l+1;
            }

            if(top -> right){
                q.push(top->right);
                level[top->right] = l+1;
            }            

        }

        res.push_back(temp);

        return res;
    }
};;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map < TreeNode*, int > level;
        map < int , vector< int>> res; 
        int maxLevel = 0;
        queue < TreeNode* > q;
        
        if(root != NULL){
            q.push(root);
            level[root] = 0;
            res[level[root]].push_back(root -> val);
        }
        
        
        while(!q.empty()){
            TreeNode *top= q.front();
            maxLevel = max(maxLevel, level[top]);
            q.pop();
            
            TreeNode* left = top -> left;
            TreeNode *right = top -> right;
            
            if(left){
                level[left] = level[top] + 1;
                res[level[left]].push_back(left -> val);
                q.push(left);
            }
            
            if(right){
                level[right] = level[top] + 1;
                q.push(right);
                res[level[right]].push_back(right -> val);
            }
        }
        
        int counter = 0;
        
        vector< vector<int> > result;
        
        while(res[counter].size() > 0){
            result.push_back(res[counter++]);
        }
        
        
        return result;
    }
};