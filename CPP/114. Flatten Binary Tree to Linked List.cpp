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
    
    void flatten(TreeNode* root) {
        if(root == NULL){
            return ;
        }

        stack < pair< TreeNode*, TreeNode*> > q;
        
        
        pair < TreeNode*, TreeNode*> pVal(root, NULL);
        q.push(pVal);
        
        while(!q.empty()){
            pair<TreeNode*, TreeNode*> top =  q.top();
            q.pop();
            
            if(top.first -> left == NULL){
                if(top.first -> right != NULL){
                    top.first -> left = top.first -> right;
                    top.first -> right = NULL;
                }
                else if(!q.empty()){
                    pair<TreeNode*, TreeNode*> secondTop = q.top();
                    top.first -> left = secondTop.first;
                    
                    if(secondTop.second -> left == secondTop.first){
                        secondTop.second -> left = NULL;
                    }
                    
                    if(secondTop.second -> right == secondTop.first){
                        secondTop.second -> right = NULL;
                    }
                    
                    q.pop();
                }
                
            }
            
            
            if(top.first -> right != NULL)
                q.push(make_pair( top.first -> right, top.first));
            
            if(top.first -> left != NULL)
                q.push(make_pair( top.first -> left, top.first));
        }
        
        
        TreeNode* cur = root;
        
        while(cur != NULL){
            if(cur -> right == NULL && cur -> left != NULL){
                cur-> right = cur -> left;
                cur -> left = NULL;
            }
            
            cur = cur -> right;

        }
    }
};

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
    void flatten(TreeNode* root) {
        
        if(root == NULL) 
            return;
        flatten(root -> left);
        flatten(root -> right);
        
        if(root -> left != NULL){
            TreeNode *temp  = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
            
            TreeNode*  cur = root->right;
            while(cur -> right != NULL){
                cur = cur -> right;
            }
            cur -> right = temp;
        }
    }
};