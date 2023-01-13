class Solution {
public:

    int dx[4] = {-1,-1,1,1};
    int dy[4] = {-1,1,-1,1};
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> dummy;
        backtrack(dummy, n,n);

        return res;
    }

    void backtrack(vector<string> grid, int n ,int sz){
        if(n == 0){
            res.push_back(grid);
        }

        string cur(sz, '.');

        grid.push_back(cur);

        for(int i = 0 ; i< cur.size() ; i++){
            if(isvalid(grid, grid.size() - 1, i)){
                grid[grid.size() - 1][i] = 'Q';
                backtrack(grid, n-1, sz);
                grid[grid.size() - 1][i] = '.';
            }
        }
    }

    bool isvalid(vector<string> grid, int x , int y){
        for(int i = 0 ; i< grid.size() ; i++){
            if(grid[i][y] == 'Q')
                return false;
        }

        for(int i = 0 ; i< grid[0].size(); i++){
            if(grid[x][i] == 'Q')
                return false;
        }

        for(int i = 0 ; i< 4 ; i++){
            int prevx = x;
            int prevy = y;
            for(int j = 0 ; j< grid.size(); j++){
                prevx += dx[i];
                prevy += dy[i];
                if(prevx >= 0 && prevx < grid.size() && prevy >=0 && prevy < grid[0].size()){
                    if(grid[prevx][prevy] == 'Q')
                        return false;
                }
            }
        }

        return true;
    }
};