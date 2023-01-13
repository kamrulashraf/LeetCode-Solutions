class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() , nums.begin() + k);
        reverse(nums.begin()+k, nums.begin() + nums.size());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        
        reverseArr(nums,0,nums.size() - 1);
        reverseArr(nums, 0, k-1);
        reverseArr(nums,k, nums.size() - 1);
    }
    
    void reverseArr(vector<int> &nums, int l ,int r){
        int m = (l+r)/2;
        
        for(int i = l, j = r ; i < j ; i++, j--){
            swap(nums[i], nums[j]);
        }
    }
};