class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> dp(nums.size(), 1);

        int res = 1;

        for(int i = 0 ; i< nums.size() ; i++){
            for(int j = 0 ; j< i ; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }

        return res;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> res (nums.size(), INT_MAX);
        int len = 0;
        for(auto &x: nums){
            int pos = lower_bound(res.begin(), res.end(), x) - res.begin();
            len = max(len, pos+1);
            res[pos] = x;
        }

        return len;
    }
};