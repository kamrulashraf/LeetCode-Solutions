class Solution {
public:
    
    vector<int> dx{0,1,0,-1};
    vector<int> dy{1,0,-1,0};
    map < int, map<int,bool> > vis;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        dfs(matrix, 0, res, 0,0);
        
        return res;
        
    }
    
    void dfs(vector<vector<int>>& matrix, int idx, vector<int>& res, int x, int y){
        
        int xx = dx[idx] + x;
        int yy = dy[idx] + y;
        
        vis[x][y] = true;
        
        if(xx >= matrix.size() || xx < 0 || yy < 0 || yy >= matrix[0].size() || vis[xx][yy]){
            xx = x - dx[idx];
            yy = y - dy[idx];
            idx = (idx+1)%4;
            
            xx = x + dx[idx];
            yy = y + dy[idx];
        }
        
        res.push_back(matrix[x][y]);

        if( xx >= 0 && xx < matrix.size() && yy >= 0 && yy < matrix[0].size() && vis[xx][yy] == false){
            dfs(matrix, idx, res, xx, yy);
        }
        
        
    }
};

class Solution {
public:
    vector<int> dx{0, 1, 0, -1};
    vector<int> dy{1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool vis[11][11] = {0};
        vector<int> res;
        int r = matrix.size();
        int c = matrix[0].size();
        int  x = 0 , y = 0;
        int dir = 0;
        while(res.size() < r*c){
            res.push_back(matrix[x][y]);
            vis[x][y] = true;

            x = x + dx[dir];
            y = y + dy[dir];
            if( x >= r || x < 0 || y >= c || y < 0 || vis[x][y]){
                x -= dx[dir];
                y -= dy[dir];
                dir = (dir+1)%4;
                x = x + dx[dir];
                y = y + dy[dir];
            }
        }

        return res;
        
    }
};