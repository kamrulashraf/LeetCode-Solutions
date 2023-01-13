class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        int res = 0;
        for(int i = 0 ; i< text1.size() ; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 0 ; i< text2.size() ; i++){
            dp[i][0] = 0;
        }
        
        // text2 horizontal
        //text1 vertical
        for(int i = 0 ; i< text1.size() ; i++){
            for(int j = 0 ; j< text2.size() ; j++){
                int x = i+1;
                int y = j+1;
                if(text1[i] == text2[j]){
                    dp[x][y] = max(dp[x][y-1], dp[x-1][y-1] + 1);
                } else{
                    dp[x][y] = max(dp[x][y-1], dp[x-1][y]);
                }
                
                res = max(dp[x][y], res);
            }
        }
        
        return res;
    }
};

class Solution {
public:

    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return lcs(text1,text2, 0 , 0);
    }

    int lcs(string &text1, string &text2, int i,int j){
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == text1.size())
            return 0;
        if(j == text2.size())
            return 0;
        if(text1[i] == text2[j]){
            return dp[i][j]  = 1 + lcs(text1, text2, i+1, j+1);
        }
        else{
            int a = lcs(text1, text2, i+1, j);
            int b = lcs(text1,text2, i, j+1);
            return dp[i][j] = max(a,b);
        }
    }
};