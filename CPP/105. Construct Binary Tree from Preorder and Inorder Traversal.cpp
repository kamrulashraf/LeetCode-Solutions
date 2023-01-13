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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *head = new TreeNode();
        makeTree(preorder, inorder, head);
        
        return head;
    }
    
    void makeTree(vector<int> preorder, vector<int> inorder, TreeNode* head){
        if(inorder.size() == 0){
            return;
        }
        int root = preorder[0];
        head -> val = root;
        
        int posInInorder = 0;
        
        for(int i = 0 ; i< inorder.size(); i++){
            if(inorder[i]== root){
                posInInorder = i;
            }
        }
        
        if(posInInorder > 0){
            TreeNode* left = new TreeNode();
            head -> left = left;
            vector<int> npreorder(preorder.begin()+1, preorder.begin() + posInInorder+1);
            vector<int> ninorder(inorder.begin(), inorder.begin() + posInInorder);
            makeTree(npreorder, ninorder, left);
        }
        
        if(posInInorder < inorder.size()-1){
            TreeNode* right = new TreeNode();
            
            head -> right = right;
            vector<int> npreorder(preorder.begin() + posInInorder+1, preorder.end());
            vector<int> ninorder(inorder.begin() + posInInorder + 1, inorder.end());
            
            makeTree(npreorder, ninorder, right);
        }
    }
};


// lastest submission
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return NULL;
        }

        TreeNode *root = new TreeNode();
        getTree(preorder,inorder, root);
        return root;
    }

    void getTree(vector<int>& preorder, vector<int>& inorder, TreeNode *root) {
        
        int pos;
        for(int i = 0 ; i< inorder.size(); i++){
            if(inorder[i] == preorder[0]){
                pos = i;
                break;
            }
        }
        root -> val = preorder[0];
        vector<int> preleft(preorder.begin() + 1, preorder.begin() + 1 + pos);
        vector<int> preright(preorder.begin() + pos + 1, preorder.end());
        vector<int> inleft(inorder.begin(), inorder.begin() + pos);
        vector<int> inright(inorder.begin() + pos + 1, inorder.end());

        if(preleft.size()){
            root -> left = new TreeNode();
            getTree(preleft, inleft, root->left);
        }

        if(preright.size()){
            root -> right = new TreeNode();
            getTree(preright, inright, root -> right);
        }
        
    }

};