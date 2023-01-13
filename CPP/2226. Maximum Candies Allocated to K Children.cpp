class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int b = 1;
        int e = 10000000;
        
        
        while(b < e){
            int m = ( (long) b + (long) e)/2;
            long long child = noOfChild(candies, m);
            if(child >= k){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return noOfChild(candies, b) < k ? b-1 : b ;
    }
    
    long long noOfChild(vector<int> &arr, int candy){
        long long res = 0;
        for(int i = 0 ; i< arr.size() ; i++){
            res +=  arr[i] / candy;
        }
        
        return res;
    }
};