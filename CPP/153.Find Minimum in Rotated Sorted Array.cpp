class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        if(nums[0] > nums[sz-1]){
            int lastel = nums[sz-1];
            int b  = 0;
            int e = sz-1;
            while(b < e){
                int m = (b+e)/2;
                if(nums[m] > lastel){
                    b = m+1;
                }
                else{
                    e = m;
                }
            }

            return nums[b];
        }
        else{
            return nums[0];
        }
    }
};