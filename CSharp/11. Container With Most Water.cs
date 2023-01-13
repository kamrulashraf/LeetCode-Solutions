public class Solution {
    public int MaxArea(int[] height) {
        int left = 0;
        int right = height.Length- 1;
        int area = Int32.MinValue;
        while(left < right){
            area = Math.Max(area, (right-left)*Math.Min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        
        return area;
    }
}