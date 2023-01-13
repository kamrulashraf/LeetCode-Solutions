class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack < pair<char ,int> > tracker;
        map <int,bool> isValid;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '('){
                tracker.push(make_pair(s[i],i));
            }
            else if(s[i] == ')'){
                if(tracker.size() == 0){
                    isValid[i] = false;
                }
                else if(tracker.top().first == '('){
                    int index = tracker.top().second;
                    isValid[index] = true;
                    isValid[i] = true;
                    tracker.pop();
                }
            }
        }
        
        string result;
        
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '(' || s[i] == ')'){
                if(isValid[i]){
                    result += s[i];
                }
                continue;
            }
            result += s[i];
        }
        
        return result;
    }
};