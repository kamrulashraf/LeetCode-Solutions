class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        int prod = 1;
        int zeroCounter = 0;
        int zeroIdx = 0;
        while(sz--){
            if(nums[sz] == 0){
                zeroCounter++;
                zeroIdx = sz;
                continue;
            }
            
            prod *= nums[sz];

        }
        
        vector <int> ret(nums.size(), 0);

        
        if(zeroCounter > 1){
            return vector<int> (nums.size(), 0);
        }
        else if(zeroCounter == 1){
            ret[zeroIdx] = prod;
            return ret;
        }
        else{
            for(int i = 0 ; i< nums.size() ; i++){
                ret[i] = prod/nums[i];
            }
        }
        
        return ret;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> postfix(nums.size(), 0);
        
        int prod = 1;
        
        for(int i = 0 ;i< nums.size(); i++){
            prefix[i] = prod = prod*nums[i];
        }
        
        prod = 1;
        
        for(int i = nums.size() - 1 ;i >= 0; i--){
            postfix[i] = prod = prod*nums[i];
        }
        
        vector<int> res;
        
        for(int i = 0 ;i< nums.size() ;i++){
            int temp = 1;
            if(i-1>=0){
                temp *= prefix[i-1];
            }
            
            if(i+1 < nums.size()){
                temp *= postfix[i+1];
            }
            
            res.push_back(temp);
        }
        
        
        return res;
    }
};