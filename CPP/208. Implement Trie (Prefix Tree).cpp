class Trie {
public:
    
    struct node{
        int val;
        node *next[26];
        
        node(){
            val = 0;
            for(int i = 0 ;i< 26 ; i++){
                next[i] = NULL;
            }
        }
    };
    
    node *root;
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node *cur = root;
        
        for(auto x: word){
            if(!cur -> next[x - 'a']){
                cur -> next[x-'a'] = new node();
            }
            
            cur = cur -> next [x - 'a'];
        }
        
        cur -> val++;
    }
    
    bool search(string word) {
        
        node *cur = root;
        
        for(auto x: word){
            int s = x-'a';
            
            if(!cur -> next[s])
                return false;
            else{
                cur = cur -> next[s];
            }
        }
        
        if(cur -> val > 0){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        node *cur = root;
        
        for(auto x: prefix){
            int s = x-'a';
            
            if(!cur -> next[s])
                return false;
            else{
                cur = cur -> next[s];
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */