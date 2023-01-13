class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxNum = std::numeric_limits<int>::min();
        
        int mostBigNum = std::numeric_limits<int>::min();
        for(int i = 0 ; i< nums.size() ; i++){
            sum += nums[i];
            if(sum <= 0){
                sum = 0;
            }
            maxNum = max(maxNum, sum);
            mostBigNum = max(mostBigNum, nums[i]);
        }
        
        return maxNum == 0 ? mostBigNum: maxNum;
    }
};