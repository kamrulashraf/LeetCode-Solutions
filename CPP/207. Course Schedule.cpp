class Solution {
public:
    
    vector <int> join[2001];
    map<int,int> visited;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        for(int i = 0 ; i< 2001 ; i++){
            join[i].clear();
        }
        visited.clear();
        
        for(int i = 0 ; i< prerequisites.size() ; i++){
            join[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        int flag = true;
        for(int i = 0 ; i< numCourses; i++){
            if(visited[i] == 0){
                flag = flag && dfs(i);
                if(flag == false)
                    return false;
            }
        }
        
        return flag;
    }
    
    bool dfs(int node){
        if(visited[node] == 1){
            return false;
        }
        visited[node] = 1;
        
        bool flag = true;
        for(auto x : join[node]){
            if(visited[x] != 2){
                flag &= dfs(x);
            }
        }
        visited[node] = 2;
        return flag;
    }
};

class Solution {
public:
    
    vector<int> graph[2001];
    int indeg[2005] = {0};
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto x: prerequisites){
            graph[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        
        queue <int> q;
        
        for(int i = 0; i< numCourses;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        int counter = 0;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            counter++;
            for(auto x: graph[top]){
                indeg[x]--;
                if(indeg[x] == 0){
                    q.push(x);
                }
            }
        }
        
        if(counter == numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};