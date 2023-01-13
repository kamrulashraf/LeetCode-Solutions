class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int,bool> vis;
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int counter = 0;
        int res = false;
        for(int i = 0 ; i< n; i++){
            if(vis[i] == false){
                counter++;
                res |= dfs(i,-1);
            }
        }

        if(counter>1){
            return false;
        }
        else
            return res? false : true;
    }

    bool dfs(int node, int parent){
        bool res = false;
        vis[node] = true;
        for(auto x: graph[node]){
            if(vis[x] == false){
                res |= dfs(x,node);
            }
            else{
                if(x != parent){
                    return true;
                }
            }
        }

        return res;
    }
};