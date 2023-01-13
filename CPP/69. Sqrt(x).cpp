class Solution {
public:
    int mySqrt(int x) {
       int b = 1;
       int e = x/2;
        while(b < e){
            long long m = (b+e)/2;
            if(m*m < x){
                b = m + 1;
            }
            else{
                e = m;
            }
        }
        
        long temp = (long) b * (long) b;
        if(temp > x){
            return b-1;
        }
        return b;
    }
};

class Solution1 {
public:
    int mySqrt(int x) {
        
       
        double  b = 0, e = x;
        
        while(e - b > .5){
            double m = (b+e)/2.0;
            
            if(m*m <= x){
                b = m;
            }
            else{
                e = m;
            }
        }
        
        double temp = ceil(b);
        if(temp*temp <= x){
            return temp;
        }
        return (int) b;
    }
};