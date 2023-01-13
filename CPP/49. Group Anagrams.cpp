class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map < string , vector<int> > store;
        
        for(int i = 0 ;i< strs.size() ; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            store[temp].push_back(i);
        }
        
        vector< vector<string> > res;
        for(auto x: store){
            vector<string> temp;
            for(auto sub : x.second){
                temp.push_back(strs[sub]);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map < string , vector<int> > store;
        
        for(int i = 0 ;i< strs.size() ; i++){
            string temp = makeHash(strs[i]);
            cout << temp << endl;
            store[temp].push_back(i);
        }
        
        vector< vector<string> > res;
        for(auto x: store){
            vector<string> temp;
            for(auto sub : x.second){
                temp.push_back(strs[sub]);
            }
            res.push_back(temp);
        }
        
        return res;
    }
    
    string makeHash(string s){
        int mark[26] = {0};
        
        for(auto x: s){
            int temp = x - 'a';
            mark[temp]++;
        }
        
        string ret;
        for(int i = 0 ; i< 26 ; i++){
            ret += to_string(mark[i]) + '#';
        }
        
        return ret;
    }
};