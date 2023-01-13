public class Solution {
    public int SearchInsert(int[] nums, int target) {
        int b = 0;
        int e = nums.Length -1;
        while(b < e){
            int m = (b+e)/2;
            
            if(nums[m] < target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        if(nums[b] < target){
            return b+1;
        }
        return b;
    }
}