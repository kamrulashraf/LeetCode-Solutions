class Solution {
public:

    int dp[17][17] = {0};
    vector<vector<string>> res;
    
    vector<vector<string>> partition(string s) {
        
        
        for(int i = 0 ; i< s.size() ; i++){
            dp[i][i] = 1;
        }
        
        for(int len = 2 ; len <= s.size() ; len++){
            for(int i = 0 ; i + len-1< s.size() ; i++){
                int j = i+len-1;
                if(s[i] == s[j]){
                    if(len>2){
                        if(dp[i+1][j-1]){
                            dp[i][j] = 1;
                        }
                        else
                            dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        vector<string> param;
        backtrack(param, 0, s);
        
        return res;
    }
    
    void backtrack(vector<string> s, int idx, string str){
        
        if(idx == str.size()){
            res.push_back(s);
            return;
        }
        for(int i = idx ; i < str.size(); i++){
            if(dp[idx][i]){
                s.push_back(str.substr(idx, i-idx+1));
                backtrack(s, i+1, str);
                s.pop_back();
            }
        }
    }
};