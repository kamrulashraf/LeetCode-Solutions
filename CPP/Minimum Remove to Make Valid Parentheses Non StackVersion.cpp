class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int blance = 0 ;
        int openCount = 0;
        
        string retV1;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '('){
                openCount++;
                blance++;
            } 
            else if(s[i] == ')'){
                if(blance == 0){
                    continue;
                }
                blance--;
            }
            retV1 += s[i];
        }
        
        string finalRes;
        // remove last open parenthesis
        for(int i = 0, counter = 0 ; i< retV1.size() ; i++){
            if(retV1[i] == '('){
                counter++;
                if(counter > openCount - blance){
                    continue;
                }
            }
            finalRes += retV1[i];
        }
        
        return finalRes;
    }
};