class Solution {
public:
    
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        backTrack(v, target, candidates, target, 0);
        return res;
    }
    
    void backTrack(
        vector<int> combination,
        int rem,
        vector<int>& can,
        int target,
        int start
    ){
        if(rem == 0){
            res.push_back(combination);
            return;
        }
        for(int i = start; i< can.size() ; i++){
            int temp = rem - can[i];
            if(temp >= 0){
                combination.push_back(can[i]);
                backTrack(combination, temp, can, target, i);
                combination.pop_back();
            }
        }
        
    }
        
};