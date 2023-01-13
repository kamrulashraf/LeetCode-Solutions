class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 1 ; i<= amount; i++){
            for(auto &x: coins){
                int target = i-x;
                if(target >= 0 && dp[target] != 0){
                    dp[i] = dp[i] != 0 ? min(dp[i], dp[target]+1) : dp[target]+1;
                }
            }
        }

        return dp[amount] - 1;
    }
};