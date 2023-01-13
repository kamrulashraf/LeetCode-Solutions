class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        vector< vector<bool> > dp(s.size()+1, vector<bool> (s.size(), false));
        for(int i = 0; i< s.size() ; i++ ){
            dp[i][i] = true;
            res++;
        }
        
        
        for(int i = 2 ; i<= s.size() ; i++){
            for(int j = 0 ; j + i-1 < s.size() ; j++){
                int idx = j + i -1;
                if(s[j] == s[idx]){
                    if(i > 2){
                        res += dp[j][idx] = dp[j+1][idx-1];
                    }                  
                    else{
                        dp[j][idx] = true;
                        res++;
                    }
                }
                else{
                    dp[j][idx] = false;
                }
            }
        }
        
        return res;
    }
};