class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int b = 1;
        int e = 1000000000;
        
        while(b < e){
            int m = ((long) b+ (long)e)/2;
            
            int time = requiredTime(piles, m);
            if(time > h){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
    
    int requiredTime(vector<int> &arr, int ability){
        int res =0;
        for(int i = 0 ; i< arr.size() ; i++){
            res += ceil( (double) arr[i]/ (double) ability);
        }
        return res;
    }
};