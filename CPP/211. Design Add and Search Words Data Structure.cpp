class WordDictionary {
public:

    struct node{
        int val;
        node *child[26];
        
        node(){
            val = 0;
            for(int i = 0 ; i< 26 ; i++){
                child[i] = NULL;
            }
        }
    };

    node *head;
    WordDictionary() {
        head = new node();    
    }
    
    void addWord(string word) {
        node *cur = head;
        for(auto x: word){
            int a = x - 'a';
            if(cur-> child[a] == NULL){
                cur -> child[a] = new node();
            }
            cur = cur-> child[a];
        }
        cur ->val++;
    }
    
    bool search(string word) {
        return searchWord(word, head);
    }

    bool searchWord(string word, node *cur){
        if(word.size() == 0){
            if(cur -> val > 0)
                return true;
            else return false;
        }
        if(word[0] == '.'){
            bool res = false;
            for(int i = 0 ; i< 26 ; i++){
                if( cur -> child[i] && word.size() > 0){
                    res |= searchWord(word.substr(1), cur-> child[i]);
                }
            }
            return res;
        }
        else{
            if(cur->child[word[0] - 'a'] && word.size() > 0){
                return searchWord(word.substr(1), cur->child[word[0] - 'a']);
            }
            else{
                return false;
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */