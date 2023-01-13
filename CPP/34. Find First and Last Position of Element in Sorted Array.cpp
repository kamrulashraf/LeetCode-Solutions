class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
        low = low < nums.size() && nums[low] == target ? low : -1;
        high = high < nums.size() && nums[high] == target ? high : -1;
        vector<int> res;
        res.push_back(low);
        res.push_back(high);
        return res;
    }
};

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lowerBound(nums,target);
        int high = upperBound(nums,target)-1;
        low = low < nums.size() && nums[low] == target ? low : -1;
        high = high < nums.size() && nums[high] == target ? high : -1;
        vector<int> res;
        res.push_back(low);
        res.push_back(high);
        return res;
    }
    
    int lowerBound(vector<int> nums, int target){
        int b = 0;
        int e = nums.size();
        
        while(b <e){
            int m = (b+e)/2;
            if(nums[m] < target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        return b;
    }
    
    int upperBound(vector<int> nums,int target){
        int b = 0;
        int e = nums.size();
        
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] <= target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        return b;
    }
};