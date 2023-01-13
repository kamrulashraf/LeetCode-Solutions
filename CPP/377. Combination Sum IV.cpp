class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i<= target ; i++){
            for(auto &x: nums){
                int target = i-x;
                if(target >= 0){
                    dp[i] =  (dp[i] + dp[target]) % INT_MAX;
                }
            }
        }
        return dp[target];
    }
};