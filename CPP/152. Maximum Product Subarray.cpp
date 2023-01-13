// max of total production, cur max , totalProduction/upfirst negative element production
// 0 will divide the array into sub problem

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int totalProd = 1;
        int curMax = INT_MIN;
        int upToFirst = 1;
        int firstNegOfSeg = 0;
        int res = INT_MIN;
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] == 0){
                totalProd = 1;
                curMax = INT_MIN;
                upToFirst = 1;
                res = max(res, 0);
                firstNegOfSeg = 0;
            }
            else{
                totalProd *= nums[i];
                curMax = max(curMax, totalProd);
                if(nums[i] < 0 && firstNegOfSeg == 0){
                    upToFirst = totalProd;
                    res = max(res, max(curMax, totalProd));
                }
                else{
                    res = max(res, max(curMax, max(totalProd, totalProd/upToFirst )));
                }
                
                if(nums[i] < 0){
                    firstNegOfSeg++;
                }
                
            }
        }
        
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int res = nums[0];
        for(int i = 1 ; i< nums.size() ; i++){
            int cur = nums[i];
            maxSoFar = max(cur, max(minSoFar*cur, maxSoFar*cur));
            minSoFar = min(cur, min(minSoFar*cur, maxSoFar*cur));
            res = max(res, maxSoFar);
        }
        
        
        return res;
    }
};