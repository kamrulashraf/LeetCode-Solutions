public class Solution {
    public int MinSubArrayLen(int target, int[] nums) {
        long sum = 0;
        int res = 1000004;
        for(int i = 0 ; i< nums.Length; i++){
            sum += nums[i];
            nums[i] = (int) sum;
        }
        
        for(int i = 0 ; i< nums.Length ; i++){
            int prevVal = 0;
            if(i == 0){
                prevVal = 0;
            }
            else{
                prevVal = nums[i-1];
            }
            int newTarget = prevVal + target;
            int pos = lowerBound(ref nums, i, newTarget);
            if(pos < nums.Length){
                res = Math.Min(res, pos-i+1);
            }
        }
        
        return res != 1000004 ? res : 0;
    }
    
    int lowerBound(ref int[] nums, int b, int target){
        int e = nums.Length;
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