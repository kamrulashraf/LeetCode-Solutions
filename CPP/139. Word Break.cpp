class Solution {
public:
    
    struct node{
        int end = 0;
        node *child[26];
        
        node(){
            for(int i =0 ;i< 26; i++){
                child[i] = NULL;
            }
        }
    };
    
    bool wordBreak(string s, vector<string>& wordDict) {
        node *root = new node();
        
        for(auto x: wordDict){
            insertTrie(root, x);
        }
        
        
        
        return call(s, root) == 2 ? true : false;
    }
    
    map <string, int> dp;
    
    int call(string s, node *root){
        node *cur = root;
        int flag = 1;
        
        for(int i = 0 ; i< s.size() ; i++){
            int x = s[i] - 'a';
            
            if(cur -> child[x]){
                cur = cur -> child[x];
            }
            else{
                break;
            }
            
            if(cur -> end > 0){
                if(i+1 == s.size()){
                    flag = 2;
                }
                else{
                    string sub = s.substr(i+1);
                    if(dp[sub] == 0){
                        dp[sub] = call(sub, root);
                        if(dp[sub] == 2){
                            flag = 2;
                        }                        
                    }
                    else if(dp[sub] == 2){
                        flag = dp[sub];
                    }
                }
            }

        }
        
        return flag;
    }
    void insertTrie(node *cur, string s){
        for(auto x: s){
            int temp = x - 'a';
            if(cur ->child[temp] == NULL)
                cur -> child[temp] = new node();
            cur = cur-> child[temp];
        }
        
        cur -> end++;
    }
};


class Solution {
public:
    
    struct node{
        int end = 0;
        node *child[26];
        
        node(){
            for(int i =0 ;i< 26; i++){
                child[i] = NULL;
            }
        }
    };
    
    bool wordBreak(string s, vector<string>& wordDict) {
        node *root = new node();
        
        for(auto x: wordDict){
            insertTrie(root, x);
        }
        
        queue < int> q;
        map < int,int> mark;
        q.push(0);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            if(top == s.size())
                return true;
            node *cur = root;
            for(int i = top ; i< s.size() ; i++){
                int x = s[i] - 'a';
                if(cur -> child[x]){
                    cur = cur -> child[x];
                }
                else{
                    break;
                }
                
                if(cur-> end > 0 && !mark[i+1]){
                    q.push(i+1);
                    mark[i+1] = 1;
                }
            }
        }
        
        
        return false;
    }
    
    
    void insertTrie(node *cur, string s){
        for(auto x: s){
            int temp = x - 'a';
            if(cur ->child[temp] == NULL)
                cur -> child[temp] = new node();
            cur = cur-> child[temp];
        }
        
        cur -> end++;
    }
};