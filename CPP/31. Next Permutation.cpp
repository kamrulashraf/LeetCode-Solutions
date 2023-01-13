class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

class Solution1 {
//     steps
//     1. find last increasing element pick. denote as ith
//     2. find from the back kth element where nums[k] >  nums[i-1] such as num[k] is minimumum among them
//     3. swap nums[i-1] and nums[k]
//     4. reverse all element after nums[i-1]
public:
    void nextPermutation(vector<int>& nums) {
        int firstSortedIndex = -1;
        int secondSortedIndex = -1;
        for(int i = 0 ; i< nums.size() - 1 ; i++){
            if(nums[i] < nums[i+1]){
                firstSortedIndex = i;
            }
        }
        
        
        int minAfterPick = INT_MAX;
        for(int i = nums.size()  - 1;firstSortedIndex > -1 && i > firstSortedIndex ; i--){
            if(nums[i] > nums[firstSortedIndex]){
                if(nums[i] <= minAfterPick){
                    secondSortedIndex = i;
                    minAfterPick = nums[i];
                }
            }
        }
        
        
        if(firstSortedIndex >= 0 && secondSortedIndex >= 0){
            swap(nums[firstSortedIndex], nums[secondSortedIndex]);
        }
        
        sort(nums.begin() + firstSortedIndex + 1 , nums.end());
        return;
    }
};