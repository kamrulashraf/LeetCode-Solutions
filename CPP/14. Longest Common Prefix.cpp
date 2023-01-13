class Solution {
public:
    
    struct Trie{
        int counter = 0;
        Trie* next[26];
        Trie(){
            counter = 0;
            for(int i = 0 ; i< 26; i++){
                next[i] = NULL;
            }
        }
    };
    string longestCommonPrefix(vector<string>& strs) {
        Trie *root = new Trie;
        int len = 0;
        for(int i = 0 ; i< strs.size() ; i++){
            len = max(len, insertTrie(strs[i], root, strs.size()));
        }
        return strs[0].substr(0, len);
    }
    
    int insertTrie(string s, Trie *root, int totalStr){
        Trie *cur = root;
        int maxPreLen = 0; 
        for(int i =  0 ; i< s.size() ; i++){
            int numIthEl = s[i] - 'a';
            
            if(cur -> next[numIthEl] == NULL){
                cur -> next[numIthEl] = new Trie();
            }
            
            cur = cur -> next[numIthEl];
            cur -> counter = cur -> counter + 1;
            if(cur -> counter == totalStr){
                maxPreLen = max(maxPreLen, i+1);
            }
        }
        return maxPreLen;
    }
};
