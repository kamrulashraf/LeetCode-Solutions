class Solution {
public:
    bool isValid(string s) {
        stack <char> firstBracket;
        stack <char> secoundBracket;
        stack <char> thirdBracket;

        string open = "({[";
        stack <char> maintainner;
        for(int i = 0 ; i< s.size() ; i++){
            if(open.find(s[i]) != string::npos){
                maintainner.push(s[i]);
            }
            else{
                if(s[i] == ')'){
                    if(maintainner.size() > 0 && maintainner.top() == '('){
                        maintainner.pop();
                    }
                    else{
                        return false;
                    }
                }

                if(s[i] == '}'){
                    if(maintainner.size() > 0 && maintainner.top() == '{'){
                        maintainner.pop();
                    }
                    else{
                        return false;
                    }
                }

                if(s[i] == ']'){
                    if(maintainner.size() > 0 && maintainner.top() == '['){
                        maintainner.pop();
                    }
                    else{
                        return false;
                    }
                }

            }
        }
        
        if(maintainner.size() > 0){
            return false;
        }
        
        return true;
    }
};