class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int data = pow(2, 2*n);
        for(int i = 1 ; i<= data ;i++){
            int temp = 2*n;
            string s;
            while(temp--){
                int temp1 = (1<<temp);
                if(i&temp1>0){
                    s += '(';
                }
                else{
                    s += ')';
                }
            }
            
            cout << s << endl;
            if(isValid(s)){
                ret.push_back(s);
            }
        }
        
        return ret;
    }
    
    bool isValid(string s){
        stack <char> st;
        
        for(auto x: s){
            if(x == '('){
                st.push(x);
            }
            else if(x == ')' && (st.empty() || st.top() != '(')){
                return false;
            }
            else{
                st.pop();
            }
            
        }
        
        if(!st.empty()){
            return false;
        }
        
        return true;
    }

     bool isValid_anotherVersion(string s){
        int open = 0;
        for(auto x: s){
            if(x == '('){
                open++;
            }
            else if(x == ')'){
                if(open > 0){
                    open--;
                }
                else{
                    return false;
                }
            }
        }
        
        if(open> 0) return false;
        
        return true;
    }
};

class Solution {
public:
    
    vector <string> ret;
    vector<string> generateParenthesis(int n) {
        backtrack("", n);
        return ret;
    }
    
    
    void backtrack(string s, int n){
        if(s.size() == 2*n){
            ret.push_back(s);
        }
        
        int open = 0, close = 0;
        for(auto x : s){
            if(x == '(')
                open++;
            else{
                close++;
            }
        }
        
        int remOpen = n - open;
        if(open > close){
            backtrack(s + ')', n);
        }
        
        if(remOpen > 0){
            backtrack(s + '(', n);
        }
    }
};