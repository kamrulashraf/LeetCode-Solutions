class Solution {
public:

    int dp[501][501] = {0};
    int minDistance(string word1, string word2) {
        memset(dp,-1, sizeof(dp));
        return minCalc(word1, word2, 0, 0);
    }

    int minCalc(string& word1, string &word2, int i,int j){
        int val = INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i >= word1.size())
            return word2.size() - j;
        
        if(j == word2.size())
            return word1.size() - i;

        if(j >= word2.size())
            return 0;
        if(word1[i] == word2[j]){
            val = min(val, minCalc(word1,word2,i+1,j+1));
        }
        else{
            val = min(val, 1+minCalc(word1,word2,i+1,j));
            val = min(val, 1+minCalc(word1,word2,i,j+1));
            val = min(val, 1+minCalc(word1,word2,i+1,j+1));
        }

        return dp[i][j] = val;
    }
};