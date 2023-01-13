class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for(int i = 0 ; i< nums1.size() ; i++){
            int val = nums1[i];
            int pos = upperBound(nums2, i, val);
            res = max(res, pos-i-1);
        }
        
        return res;
    }
    
    
    int upperBound(vector<int> &nums, int b, int key){
        int e = nums.size();
        while(b < e){
            int m = (b+e)/2;
            if(nums[m] >= key){
                b = m+1;
            }
            else{
                e = m;
            }
        }
    
        return b;
    }
};