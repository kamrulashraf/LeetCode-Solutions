class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target == 'z'){
            target = 'a';
        }
        else{
            target++;
        }
        
        int b = 0, e = letters.size();
        
        while(b < e){
            int m = (b+e)/2;
            if(letters[m] < target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b < letters.size() ? letters[b] : letters[0];
        
    }
};