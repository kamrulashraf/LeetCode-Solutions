class Solution {
public:
    unordered_map<int,vector<int>> graph;
    unordered_map<int,bool> vis;

    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto &x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        int res = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                res++;
                dfs(i);
            }
        }

        return res;
    }

    void dfs(int node){
        vis[node] = true;
        for(auto x: graph[node]){
            if(!vis[x])
                dfs(x);
        }    
    }
};