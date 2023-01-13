class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int, int> culSum;
        int res = 0;
        int sum = 0;
        
        for(int i = 0 ; i< nums.size() ; i++){
            sum += nums[i];
            if(sum == k){
                res++;
            }
            
            int alternateValue = sum - k;
            if(culSum[alternateValue] > 0){
                res+= culSum[alternateValue];
            }
            culSum[sum]++;
        }
        return res;
    }
};