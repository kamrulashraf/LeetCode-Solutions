class Solution {
public:

    int rob(vector<int>& nums) {
        int dp[105][2] = {0};        

        for(int i = 0 ; i< nums.size(); i++){
            dp[i+2][0] = max(dp[i+1][1], dp[i+1][0]);
            dp[i+2][1] = max(dp[i][1] + nums[i], dp[i][0] + nums[i]);
        }
        
        // for(int i = 0 ;i< nums.size() + 2 ; i++){
        //     cout << dp[i][0] << ' ' << dp[i][1] << endl;
        // }
        return max(dp[nums.size() + 1][0], dp[nums.size() + 1][1]);
        
    }
};

class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 2 , 0);        

        for(int i = 0 ; i< nums.size(); i++){
            dp[i+2] = max(dp[i] + nums[i] , dp[i+1]);
        }
        
        
        return dp[nums.size() + 1];
        
    }
};