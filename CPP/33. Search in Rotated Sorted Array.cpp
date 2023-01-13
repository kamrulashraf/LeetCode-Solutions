class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = findBreakPoint(nums);
        
        int index = lower_bound(nums.begin(), nums.begin() + (pos-1), target) - nums.begin();
        if(index < nums.size() && nums[index] == target){
            return index;
        }
        
        if(pos > 0){
            index = lower_bound(nums.begin() + pos, nums.end(), target) - nums.begin();
            if(index < nums.size() && nums[index] == target){
                return index;
            }
        }
        
        return -1;
    }
    
    int findBreakPoint(vector<int> &nums){
        int firstVal = nums[0];
        int b= 0 ; 
        int e = nums.size();
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] >= firstVal){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int firstElement = nums[0];
        int lastElement = nums[nums.size() - 1];
        int b = 0;
        int e = nums.size();
        while(b < e){
            int m = (b+e)/2;
            if( (nums[m] <= lastElement && nums[m] < target &&  target <= lastElement) || (nums[m] > lastElement && (target > nums[m] || target <= lastElement)) ){
                b = m+1;
            }
            else{
                e = m;
            }
        }
          
        return b< nums.size() && nums[b] == target ? b : -1;
    }
};