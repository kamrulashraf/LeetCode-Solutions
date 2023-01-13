public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int leftPointer = 0;
        
        for(int i = 0 ; i< nums.Length ; i++){
            if(nums[i] != val){
                swap(ref nums[i], ref nums[leftPointer]);
                leftPointer++;
            }
        }
        
        return leftPointer;
    }
    
    void swap(ref int a , ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
}

public class Solution1 {
    public int RemoveElement(int[] nums, int val) {
        int lastPointer = nums.Length;
        int i = 0;
        while(i < lastPointer){
            if(nums[i] == val){
                swap(ref nums[i], ref nums[lastPointer-1]);
                lastPointer--;
            }    
            else{
                i++;
            }
        }
        
        return lastPointer;
    }
    
    void swap(ref int a , ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
}