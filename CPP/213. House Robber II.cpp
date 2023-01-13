class Solution {
public:

    int dp[101][2];
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return getMax(nums,0,true);
    }

    int getMax(vector<int>& nums, int i, bool canTakeLast) {
 

        if(i >= nums.size()){
            return 0;
        }

        if(dp[i][canTakeLast] != -1)
            return dp[i][canTakeLast];
        int res1 = 0, res2 = 0;
        
        if(nums.size()-1 != i || (nums.size()-1 == i && canTakeLast))
            res1 = nums[i] + getMax(nums, i+2, i==0? false : canTakeLast);
        
        res2 = getMax(nums,i+1,canTakeLast);
        return dp[i][canTakeLast] = max(res1, res2);
    }
};