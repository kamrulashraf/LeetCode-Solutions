class Solution {
public:
    
    vector < string > res; 
    vector<string> letterCombinations(string digits) {
        map< int , string> s;
        s[2] = "abc";
        s[3] = "def";
        s[4] = "ghi";
        s[5] = "jkl";
        s[6] = "mno";
        s[7] = "pqrs";
        s[8] = "tuv";
        s[9] = "wxyz";
        
        
        call("", digits, s);
        
        return res;
    }
    
    void call(string strSoFar, string digits, map<int ,string>& s){
        if(digits.size() == 0){
            if(strSoFar.size())
                res.push_back(strSoFar);
            return;
        }
        
        
        for(auto x: s[digits[0] - '0']){
            call(strSoFar + x, digits.substr(1), s);
        }
    }
};