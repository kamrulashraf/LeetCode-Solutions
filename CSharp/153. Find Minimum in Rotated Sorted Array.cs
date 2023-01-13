public class Solution {
    public int FindMin(int[] nums) {
        int firstElement = nums[0];
        
        int b = 0 ;
        int e = nums.Length;
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] >= firstElement){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b < nums.Length ? nums[b] : nums[0];
    }
}