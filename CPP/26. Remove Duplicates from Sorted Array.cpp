class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        
        int leftPointer = 1;
        for(int i = 1 ; i< nums.size() ; i++){
            if(nums[i] > nums[leftPointer-1]){
                if(i != leftPointer){
                    swap(nums[i], nums[leftPointer]);
                }
                leftPointer++;
            }
        }
        
        return leftPointer;
    }
};