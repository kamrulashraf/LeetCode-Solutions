//  ()(())(())
//  memorize previous valid parenthesis. if get new valid parenthesis. merge with previous parenthesis
class Solution {
public:
    int longestValidParentheses(string s) {
        int memo[30004];
        memset(memo, 0 , sizeof(memo));
        int prev = 0, prevIdx = -1;
        int res = 0;
        stack<int> st;

        for(int i = 0 ; i< s.size() ; i++){
            char x  = s[i];

            if(x == '('){
                st.push(i);
            }
            else{
                if(st.size() == 0){
                    prev = 0;
                }
                else{
                    int cur = i-st.top()+1;

                    prev = st.top()- 1 >= 0 ? memo[st.top()-1] : 0 ;
                    res = max( prev + cur, res);
                    memo[i] = prev+cur;

                    st.pop();
                }
            }
        }

        return res;
    }
};