class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        
        int sz = nums.size() - 1;
        dp[sz] = 1;
        sz--;
        for(int i = sz; i>= 0 ; i--){
            int last = min(i + nums[i], sz+1);
            if(dp[i+1] - dp[last+1] > 0){
                dp[i] = dp[i+1] + 1;
            }
            else{
                dp[i] = dp[i+1];
            }
        }
        
        return dp[0] - dp[1];
    }
};