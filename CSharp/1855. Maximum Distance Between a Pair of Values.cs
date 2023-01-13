public class Solution {
    public int MaxDistance(int[] nums1, int[] nums2) {
        int secondArrPointer = 0;
        int res = 0;
        for(int i = 0 ; i< nums1.Length ; i++){
            int val = nums1[i];
            while(secondArrPointer < nums2.Length && nums2[secondArrPointer] >= val){
                res = Math.Max(res , secondArrPointer - i);
                secondArrPointer++;
            }
        }
        
        return res;
    }
}