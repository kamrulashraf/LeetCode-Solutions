class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int res = INT_MIN;
        while(left < right){
            res = max(res, (right-left) * min(height[left], height[right]) );
            if(height[left] <= height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return res;
    }
};