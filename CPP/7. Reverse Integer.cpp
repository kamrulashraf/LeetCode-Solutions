class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while(x){
            int reminder = x%10;
            if(reverse < 0){
                if(reverse == INT_MIN/10){
                    if(reminder < -8){
                        return 0;
                    }
                }
                else if(reverse < INT_MIN/10){
                    return 0;
                }
            }
            else{
                if(reverse == INT_MAX/10){
                    if(reminder > 7){
                        return 0;
                    }
                }
                else if(reverse > INT_MAX/10){
                    return 0;
                }
            }
            
                
            reverse *= 10;
            reverse += reminder;
            x/= 10;
        }
        
        return reverse;
    }
};