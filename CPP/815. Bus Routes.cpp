class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target){
            return 0;    
        }
        
        map < int ,vector<int> > connections;
        for(int i = 0 ; i< routes.size() ; i++){
            for(int j = 0 ; j< routes[i].size() ; j++){
                connections[routes[i][j]].push_back(i);
            }
        }
        
        queue <int> tracker;
        map <int, int> level;
        for(int i = 0 ; i< connections[source].size() ; i++){
            level[connections[source][i]] = 1;
            tracker.push(connections[source][i]);
        }
        
        
        while(tracker.size() > 0){
            int parent = tracker.front();
            tracker.pop();
            for(int i = 0 ; i< routes[parent].size() ; i++){
                int el = routes[parent][i];
                for(int j = 0 ; j< connections[el].size() ; j++){
                    int node = connections[el][j];
                    if(level[node] == 0){
                        tracker.push(node);
                        level[node] = level[parent] + 1;
                    }
                }
            }
        }
        
        int result;
        int hasTargetBusStop = false;
        for(int i = 0 ; i< connections[target].size() ; i++){
            hasTargetBusStop = true;
            result = min(result, level[connections[target][i]]);
        }
        
        return result > 0 && hasTargetBusStop == true ? result : -1 ;
    }
};