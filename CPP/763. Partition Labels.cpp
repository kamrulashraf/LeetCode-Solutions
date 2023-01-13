class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        
        unordered_map<char,int> vis;
        int idx = 0;
        for(auto x: s){
            vis[x] = idx++;
        }
        
        int lastIdx = 0;
        int lastPicked= -1;
        for(int i = 0 ; i< s.size() ; i++){
            lastIdx = max(lastIdx, vis[s[i]]);
            
            if(i == lastIdx){
                res.push_back( i - lastPicked);
                lastPicked = i;
            }
        }
        
        return res;
    }
};