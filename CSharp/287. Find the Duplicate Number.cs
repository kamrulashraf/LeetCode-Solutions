public class Solution {
    public int FindDuplicate(int[] nums) {
        Array.Sort(nums);
        return GetPostion(ref nums);
    }
    
    private int GetPostion(ref int[] nums){
        int b = 0;
        int e = nums.Length;
        
        while(b < e){
            int m = (b+e)/2;
            if(m <= nums[m]-1){
                b = m + 1;
            }
            else{
                e = m;
            }
        }
        
        return nums[b];
        
    }
}