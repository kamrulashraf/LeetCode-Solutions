class Solution {
public:
    map<int,vector<int>> g;
    map<int,int> indeg;
    string alienOrder(vector<string>& words) {
        for(int i=0; i< words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                bool isvalid = makeGraph(words[i], words[j]);
                if(!isvalid){
                    return "";
                }
            }
        }
        set < char> node;
        for(auto x: words){
            for(auto ch: x){
                node.insert(ch);
            }
        }

        queue<int> q;
        for(auto x: node){
            if(indeg[x] == 0){
                q.push(x);
            }
        }

        string res = "";
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            res += top;
            for(auto x: g[top]){
                indeg[x]--;
                if(indeg[x] == 0)
                {
                    q.push(x);
                }
            }
        }

        if(res.size() == node.size()){
            return res;
        }
        else{
            return "";
        }
    }

    bool makeGraph(string a, string b){
        for(int i = 0 ;i< a.size(); i++){
            if(i >= b.size()){
                return false;
            }
            if(a[i] != b[i]){
                
                g[a[i]].push_back(b[i]);
                indeg[b[i]]++;
                break;
            }
        }
        return true;
    }
};