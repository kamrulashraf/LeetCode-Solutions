class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(auto &x: s){
            if(isalnum(x))
                temp += tolower(x);
        }

        
        for(int i = 0, j = temp.size() -1 ; i< temp.size()/2; i++, j--){
            if(temp[i] != temp[j])
                return false;
        }
        return true;
    }
};