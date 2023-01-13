class Solution {
public:
    map<int,int> dp;
    unordered_map<int,int> mark;

    int longestConsecutive(vector<int>& nums) {

        for(int i= 0; i < nums.size(); i++){
            mark[nums[i]]++;
        }

        int res = 0;

        for(int x: nums){
            if(dp[x] == 0){
                res = max(call(x),res);
            }
        }

        return res;
    }

    int call(int x){
        if(dp[x])
            return dp[x];
        if(mark[x] == 0){
            return 0;
        }
        else{
            return dp[x] = 1 + call(x+1);
        }
    }
};