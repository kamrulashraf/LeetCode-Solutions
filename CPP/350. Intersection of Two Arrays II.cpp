class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int beginPointer = 0;
        vector <int> res;
        for(int i = 0 ; i< nums1.size() ; i++){
            int pos = lower_bound(nums2.begin() + beginPointer, nums2.end(), nums1[i]) - nums2.begin();
            if(pos < nums2.size() && nums2[pos] == nums1[i]){
                res.push_back(nums1[i]);
                beginPointer = pos+1;
            }
        }
        
        return res;
    }
};