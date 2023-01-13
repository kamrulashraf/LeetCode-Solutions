class Solution {
public:
    int specialArray(vector<int>& nums) {
        int b = 0, e = 1000;
        sort(nums.begin(), nums.end());
        while(b < e){
            int m = (b+e)/2;
            int pos = lower_bound(nums.begin(), nums.end(), m) - nums.begin();
            int greaterVal = nums.size() - pos;
            if(greaterVal > m){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        int greaterEl = nums.size() -  (lower_bound(nums.begin(), nums.end(), b) - nums.begin());
        if(greaterEl == b){
            return b;
        }
        else{
            return -1;
        }
    }
};