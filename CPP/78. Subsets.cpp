class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > res;
        
        
        int sz = (1<<nums.size());
        for(int i = 0 ; i< sz ; i++){
            vector<int> temp;
            for(int j = 0 ; j< nums.size() ;j++){
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
};

class Solution {
public:
    vector< vector<int> > res;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> init;
        backtrack(init, -1, nums);
        
        return res;
    
    }
    
    void backtrack(vector<int> sub, int idx, vector<int>& nums){
        idx++;

        if(idx == nums.size()){
            res.push_back(sub);
            return;
        }
        
        backtrack(sub, idx, nums);
        sub.push_back(nums[idx]);
        backtrack(sub, idx, nums);
        
    }
};