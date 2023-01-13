// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int b = 1 , e = n;
        while(b < e){
            int m = ((long)b+ (long)e) >> 1;
            if(!isBadVersion(m)){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
};