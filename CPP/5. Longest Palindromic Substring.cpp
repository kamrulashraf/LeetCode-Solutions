class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1003][1001];
            
        string ret = "";

        for(int i = 0 ; i< s.size() ; i++){
            dp[i][i] = true;
            if(i+1 < s.size()){
                dp[i][i+1] = s[i] == s[i+1] ? true : false;
            }
        }


        for(int i = 3 ; i<= s.size() ; i++){
            for(int j = 0 ; j + i <= s.size() ; j++){
                int nxt = i+j-1;
                dp[j][nxt] = dp[j+1][nxt-1] && s[j] == s[nxt] ? true : false;
            }
        }

        for(int i = s.size() ; i>= 0 ; i--){
            for(int j = 0 ; j + i <= s.size() ; j++){
                int nxt = i+j-1;
                if(dp[j][nxt]){
                    return s.substr(j,i);
                }
            }   
        }
        
        return ret;
    }
};

class Solution1 {
public:
    string longestPalindrome(string s) {
        int reti, rety;
        int maxLen = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int left, right;
            left = i-1;
            right = i+1;
            
            getMaxLetAndIndex(s, left, right, reti, maxLen);
            
            left = i;
            right = i+1;
            
            getMaxLetAndIndex(s, left, right, reti, maxLen);
            
        }
        if(maxLen == 0 && s.size() > 0){
            return s.substr(0,1);
        }
        return s.substr(reti, maxLen);
    }
    
    void getMaxLetAndIndex(string& s, int left, int right, int& reti, int &maxLen){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            int len = right-left+1;
            if(len > maxLen){
                reti = left;
                maxLen = len;
            }
            left--;
            right++;
        }
    }
};