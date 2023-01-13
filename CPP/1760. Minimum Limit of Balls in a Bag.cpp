class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end(), greater<int>());
        int b = 1;
        int e = nums[0];
        
        while(b < e){
            int m = (b+e)/2;
            int no = noOfOperation(nums, m);
            if(no > maxOperations){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
    
    int noOfOperation(vector<int> &nums, int minVal){
        int requiredOperation = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] <= minVal){
                break;
            }
            
            requiredOperation += calCulateOperation(nums[i], minVal);
            
        }
        
        return requiredOperation;
    }
    
    int calCulateOperation(int val, int minVal){
        if(val%minVal == 0){
            return val/minVal -1;
        }
        else{
            return (int) ceil((double) val/ (double) minVal) -1;
        }
    }
};