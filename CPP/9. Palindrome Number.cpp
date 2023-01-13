class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long reverseNum = 0;
        int saveNum = x;
        while(x){
            reverseNum = 10*reverseNum;
            reverseNum += x%10;
            x /= 10;
        }
        
        if((long) saveNum == reverseNum){
            return true;
        }
        else{
            return false;
        }
    }
};

class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x !=0 && x%10 ==0)){
            return false;
        }
        int reverseNum = 0;
        int saveNum = x;
        while(reverseNum < x){
            reverseNum = 10*reverseNum;
            reverseNum += x%10;
            x /= 10;
        }
        
        if(reverseNum  == x || reverseNum/10 == x){
            return true;
        }
        
        return false;
    }
};