class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i = 0 ; i*i <= c ; i++){
            long temp = c - i*i;
            long root = (long) squreRoot(temp);
            if(root * root == temp){
                return true;
            }
        }
        return false;
    }
    
    int squreRoot(int n){
        int b = 0 , e = n;
        while(b < e){
            long m = ((long) b + (long) e)/2;
            if(m*m < n){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
   
    
    
};