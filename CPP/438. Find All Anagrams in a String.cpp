class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // map < int, map< char, int> > count;
        
        int count[30004][125] = {0};
        map <char, int> pcount;
        
        int idx = 0;
        for(auto x: s){
            if(idx > 0){
                for(int i = 'a'; i<= 'z'; i++){
                    count[idx][i] = count[idx-1][i];
                }
            }
            
            
            count[idx][x]++;
            idx++;
        }    
        
        
        for(auto x: p){
            pcount[x]++;
        }
        
        string anagramHash;
        
        
        for(int i = 'a'; i<='z'; i++){
            anagramHash += to_string(pcount[i]) + '#';
        }
        

        vector<int> res;
        for(int i = 0 ; i + p.size()-1< s.size() ; i++){
            int next = i + p.size() - 1;
            
            string hash;
            for(int j = 'a' ; j <= 'z'; j++){
                int c = count[next][j]- (i>0? count[i-1][j] : 0);
                hash += to_string(c) + '#';
            }
            
            if(hash == anagramHash){
                res.push_back(i);
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int smark[27] = {0};
        int pmark[27] = {0};
        
        for(auto x: p){
            pmark[x-'a']++;
        }
        
        
        for(int i = 0 ;i < p.size()-1 && i < s.size() ; i++){
            smark[s[i]-'a']++;
        }
        
        vector<int> res;
        for(int i = p.size()-1 ; i<s.size(); i++){
            smark[s[i]- 'a']++;

            if(checkCount(smark,pmark)){
                res.push_back(i-p.size() + 1);
            }
            
            int prev = i-p.size()+1;
            
            smark[s[prev]- 'a']--;
        }
        
        return res;
    }
    
    bool checkCount(int (&smark)[27], int (&pmark)[27]){
        for(int i = 0 ; i< 26 ; i++){
            if(smark[i] != pmark[i])
                return false;
        }
        return true;
    }
    
};