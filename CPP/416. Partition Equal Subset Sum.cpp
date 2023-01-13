class Solution {
public:
    int dp[20005][201] = {0};

    bool canPartition(vector<int>& nums) {
        memset(dp,-1, sizeof(dp));
        int sum = 0;
        for(int x: nums){
            sum += x;
        }
        
        if(sum%2==1){
            return false;
        }
        
        return call(sum/2, 0, nums);
    
    }
    
    bool call(int need, int idx, vector<int>& nums){
        
        if(need < 0)
            return false;
        
        if(idx >= nums.size()){
            if(need == 0){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(dp[need][idx] != -1){
            return dp[need][idx];
        }
        
        
        bool take = call(need - nums[idx], idx+1, nums);
        bool nottake = call(need, idx+1, nums);
        
        return dp[need][idx] = take|nottake;
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto x: nums)
            sum += x;
        
        if(sum%2)
            return false;
        
        int target = sum/2;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(auto x : nums){
            
            for(int i =  target; i-x >= 0 ; i--){
                int idx = i-x;
                
                dp[i] = dp[i] | dp[idx];
            }
        }
        
        return dp[target];
    }
};