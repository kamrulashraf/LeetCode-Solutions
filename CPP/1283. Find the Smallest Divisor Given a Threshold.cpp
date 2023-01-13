class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int b= 1;
        int e= 1000000;
        
        while(b < e){
            int m = ((long)b+ (long)e)/2;
            long long sum = calculateDivSum(nums,m);
             // cout << sum << ' ' << m << endl;
            if(sum <= threshold){
                e = m;
            } else{
                b = m+1;
            }
        }
        
        return e;
    }
    
    long calculateDivSum(vector<int> &nums, int m){
        long long ret = 0;
        for(int i = 0 ; i< nums.size(); i++){
            ret += ceil((double) nums[i] / m);
        }
        
        return ret;
    }
};