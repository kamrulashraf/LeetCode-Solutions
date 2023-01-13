class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map <int,int> mark;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i< nums.size() ; i++){
            towSum(nums, -nums[i], res, i+1);

            while(i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
          
        }
        
        return res;
    }
    
    
    void towSum(vector<int>&nums, int target, vector<vector<int>>&ret, int left){
        int right = nums.size() - 1;
        
        while(left < right){
            if(nums[left] + nums[right] == target){
                vector<int> temp {-target, nums[left], nums[right]};
                ret.push_back(temp);
                int tempNum = nums[left];
                while(tempNum == nums[left] && left < right){
                    left++;
                }
            }
            else if(nums[left] + nums[right] > target){
                right--;
            } else{
                left++;
            }
            
        }
    }
};