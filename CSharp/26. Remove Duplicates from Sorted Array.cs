public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int leftPointer = 1;
        if(nums.Length == 1){
            return 1;
        }
        
        
        for(int i = 1 ; i< nums.Length ; i++){
            if(nums[leftPointer-1] < nums[i]){
                if(i != leftPointer){
                    swap(ref nums[i] , ref nums[leftPointer]);
                }
                leftPointer++;
            }
        }
        
        return leftPointer;
    }
    
    private void swap(ref int a, ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
}