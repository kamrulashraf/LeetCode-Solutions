class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = findBreakPoint(nums);
        // cout << pos << endl;
        int index = lower_bound(nums.begin(), nums.begin() + (pos-1), target) - nums.begin();
        if(index < nums.size() && nums[index] == target){
            return true;
        }
        
        if(pos > 0){
            index = lower_bound(nums.begin() + pos, nums.end(), target) - nums.begin();
            if(index < nums.size() && nums[index] == target){
                return true;
            }
        }
        
        return false;
    }
    
    int findBreakPoint(vector<int> &nums){
        int firstVal = nums[0];
        int b= 0 ; 
        int e = nums.size();
        
        if(nums.size() > 1){
            while(b < nums.size() && nums[b] == nums[0]){
                b++;
            }
            b--;
        }
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] > firstVal || (m+1 < nums.size() && nums[m+1] < nums[m])){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
};

class Solution1 {
public:
    bool search(vector<int>& nums, int target) {
        int b =  0;
        int e = nums.size();
        
        if(nums.size() >  1 ) {
            b = 1;
            while(b < nums.size() && nums[b] == nums[0]){
                b++;
            }
            b--;
        }
        
        int firstEl = nums[b];
        int lastEl = nums[nums.size()  -1];
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] == target){
                b = m;
                break;
            }
            if( 
                (isInFirstPart(nums, m) && (nums[m] < target || (nums[m] > target && target < firstEl)))
                ||
                (!isInFirstPart(nums, m) && nums[m] < target && target <= lastEl)            
            ){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b < nums.size() && nums[b] == target ? true : false;
    }
    
    
    bool isInFirstPart(vector <int> &nums, int index){
        if(index == 0){
            return true;
        }
        else if(nums[0] < nums[index]){
            return true;
        }
        
        return false;
    }
};