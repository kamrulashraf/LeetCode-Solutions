class Solution {
public:
    string minWindow(string s, string t) {
        int tmap[130] = {0};
        int smap[130] = {0};
        
        
        for(auto x: t){
            tmap[x]++;
        }
        
        int i = 0 , j= 0;
        int winSz = INT_MAX, st = -1;
        while(j < s.size()){
            smap[s[j]]++;
            while(isValidWin(tmap, smap) && i <= j){
                int diff = j-i+1;
                if(diff < winSz){
                    winSz = diff;
                    st = i;
                }
                smap[s[i]]--;
                i++;
            }
            
            j++;
        }
        if(st < 0){
            return "";
        }
        else{
            return s.substr(st, winSz);
        }
    }
    
    bool isValidWin(int (&tmap)[130], int (&smap)[130]){
        for(int i = 'a' ; i<= 'z'; i++){
            if(smap[i] < tmap[i])
                return false;
        }
        
        for(int i = 'A' ; i<= 'Z'; i++){
            if(smap[i] < tmap[i])
                return false;
        }
        
        return true;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int tmap[130] = {0};
        int smap[130] = {0};
        
        
        for(auto x: t){
            tmap[x]++;
        }
        
        int i = 0 , j= 0;
        int winSz = INT_MAX, st = -1;
        while(j < s.size()){
            smap[s[j]]++;
            
            if(isValidWin(tmap, smap)){
                do{
                    int diff = j-i+1;
                    if(diff < winSz){
                        winSz = diff;
                        st = i;
                    }
                    smap[s[i]]--;
                    i++;
                } while( (smap[s[i-1]] >= tmap[s[i-1]] || tmap[s[i-1]] == 0  )&& i <= j);
            }
            
            
            j++;
        }
        if(st < 0){
            return "";
        }
        else{
            return s.substr(st, winSz);
        }
    }
    
    bool isValidWin(int (&tmap)[130], int (&smap)[130]){
        for(int i = 'a' ; i<= 'z'; i++){
            if(smap[i] < tmap[i])
                return false;
        }
        
        for(int i = 'A' ; i<= 'Z'; i++){
            if(smap[i] < tmap[i])
                return false;
        }
        
        return true;
    }
};

// optiomize solution
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mark;
        int counter = 0;

        for(auto x: t){
            mark[x]++;
            counter += mark[x] == 1 ? 1 : 0;

        }

        int res = INT_MAX;
        int stIdx = 0;
        int left = 0;
        for(int i = 0 ; i< s.size() ; i++){
            mark[s[i]]--;
            if(mark[s[i]] == 0)
                counter--;

            if(counter == 0){
                while(counter == 0 && left <= i){
                    if(i-left+1 < res){
                        res = i-left+1;
                        stIdx = left;
                    }
                    mark[s[left]]++;
                    if(mark[s[left]] == 1){
                        counter++;
                    }
                    left++;
                }
            }
        }
        res = res == INT_MAX ? 0 : res;
        return s.substr(stIdx, res);
    }
};