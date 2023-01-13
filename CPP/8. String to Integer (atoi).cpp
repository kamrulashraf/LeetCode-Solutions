class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        bool isDigitFound = false;
        bool isNegative = false;
        for(int i = 0 ; i< s.size() ; i++){
            
            // check "+0 000"
            if(s[i] == ' ' && !isDigitFound){
                continue;
            }
            
            // check "fsdfdsf25345"
            if( s[i] != '-' && s[i] != '+' && !checkIsDigit(s[i])){
                break;
            }
               
            // check "-454fsdf"
            if(!checkIsDigit(s[i]) && isDigitFound){
                break;
            }
            
            if(checkIsDigit(s[i]) || s[i] == '-' || s[i] == '+'){
                isDigitFound = true;
                if(s[i] == '-'){
                    isNegative = true;
                    continue;
                }
                if(s[i] == '+'){
                    continue;
                }
                
                if(ret < 0){
                    if(ret == INT_MIN/10){
                        if(s[i] > '8'){
                            return INT_MIN;
                        }
                    }
                    else if(ret < INT_MIN/10){
                        return INT_MIN;
                    }
                }
                if(ret >= 0){
                    if(ret == INT_MAX/10){
                        if(s[i] > '7'){
                            return INT_MAX;
                        }
                    }
                    else if(ret > INT_MAX/10){
                        return INT_MAX;
                    }
                }
                
                ret *= 10;
                
                if(isNegative){
                    ret -= (s[i] - '0');
                }
                else{
                    ret += s[i] - '0';                    
                }
                
            }
        }
        
        return ret;
    }
    
    bool checkIsDigit(char c){
        for(int i = '0' ; i<= '9' ; i++){
            if(c == i){
                return true;
            }
        }
        
        return false;
    }
};