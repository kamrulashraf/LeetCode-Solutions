class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0){
            long newN = -1*(long)n;
            return (double) (1.0/bigPowFunction(x, newN));
        }
        else{
            return bigPowFunction(x,n);
        }
        
    }
    
    double bigPowFunction(double x , long n){
        if(n == 0){
            return 1.0;
        }
        if(n&1){
            return x*bigPowFunction(x, n-1);
        }
        else{
            double tempRes = bigPowFunction(x, n/2);
            return tempRes*tempRes;
        }
    }
};