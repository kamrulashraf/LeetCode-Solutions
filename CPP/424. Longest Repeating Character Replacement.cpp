class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<vector<int>> dp (s.size() + 2, vector<int>(26, 0));

        for(int i = 0 ; i< s.size() ; i++){
            dp[i+1][s[i] - 'A']++;
            for(int j = 0 ; j< 26; j++){
                dp[i+1][j] += dp[i][j];
            }
        }

        int res = 0;
        for(int c = 0; c < 26; c++){
            for(int i = 0 ; i < s.size() ; i++){
                int nxt = getMax(dp, k, c, i, s.size());
                res = max(res, nxt-i+1);
            }
        }

        return res;
    }

    int getMax(vector<vector<int>> &dp, int k,char c, int b,int e){
        int saveb =b;
        while(b<e){
            int m = (b+e)/2;
            // cout << (m-saveb+1) << ' ' << dp[m+1][c] << ' ' << dp[b][c] << endl;
            int count = (m-saveb+1) -  (dp[m+1][c] - dp[saveb][c]);
            if(count <= k){
                b = m+1;
            }
            else{
                e = m;
            }
        }

        return b-1;
    }
};