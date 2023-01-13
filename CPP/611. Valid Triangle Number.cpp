class Solution {
public:
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int res = 0;
        
        for(int i = 0 ; i< nums.size() ; i++){
            int val = nums[i];
            int left = i+1;
            
            if(left >= nums.size()){
                break;
            }
            
            int right = nums.size() - 1;
            while(left < right){
                while(right > left && nums[left] + nums[right] <= nums[i]){
                    right--;
                }
                res += right - left;
                left++;
            }
        }
        
        return res;
        
    }
};


// some property like if c > a and c > b then a+c > b and b + c > a
class Solution1 {
public:
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        
        for(int i = 0 ; i< nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                int pos = lower_bound(nums.begin() + j+1, nums.end(), nums[i] + nums[j]) - nums.begin();
                res += pos - j - 1;
            }
        }
        
        return res;
        
    }
    
    
    int lowerBound(vector<int> nums, int target, int b ,int e){
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] >= target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
};