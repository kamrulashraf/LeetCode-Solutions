class Solution {
public:
    
    bool isnum(char s){
        return s >= '0' && s <= '9';
    }
    
    string decodeString(string s) {
        
        int i = 0;
        string res;
        while(isalpha(s[i]))
            res += s[i++];
        
        
        
        string temp;
        
        int j = i;
        if(isnum(s[i])){
            while(isnum(s[i])){
                temp += s[i++];
            }
            
            int num = stoi(temp);

            
            int open = 0;
            j = i;
            while(1){
                if(s[j] == '['){
                    open++;
                }
                if(s[j] == ']'){
                    open--;
                }
                if(s[j] == ']' && open ==0)
                    break;
                j++;
            }
            
            for(int it = 0 ; it< num; it++){
                res += decodeString(s.substr(i+1, j-i-1));
            }
        }
        
        res =  res + ((j+1) < s.size() ? decodeString(s.substr(j+1)) : "");
        return res;
    }
    
    
};