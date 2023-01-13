public class Solution {
    public int Search(int[] nums, int target) {
        int pos = findBreakPoint(ref nums);
        int index = 0;
        
        index = lowerBound(ref nums, target, 0, pos-1);
        if(index < nums.Length && nums[index] == target){
            return index;
        }
        if(pos > 0){
            index = lowerBound(ref nums, target, pos, nums.Length);
            if(index < nums.Length && nums[index] == target){
                return index;
            }
        }
        
        return -1;
    }
    
    int findBreakPoint(ref int[] nums){
        int firstVal = nums[0];
        int b = 0 ;
        int e = nums.Length;
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] >= firstVal){
                b = m+ 1;
            }
            else{
                e = m;
            }
        }
        return b;
    }
    
    int lowerBound(ref int[] nums, int target, int b, int e){
        while(b < e){
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
}