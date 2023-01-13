class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), INT_MAX));
        
        dp[0][0] = grid[0][0];
        
        for(int i = 0 ; i< grid.size() ; i++){
            for(int j = 0 ; j< grid[i].size() ; j++){
                int x = i-1;
                int y = j-1;
                
                if(x >= 0){
                    dp[i][j] = min(dp[x][j] + grid[i][j], dp[i][j]);
                }
                if(y >= 0){
                    dp[i][j] = min(dp[i][y] + grid[i][j], dp[i][j]);
                }
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        for(int i = 0 ; i< grid.size() ; i++){
            for(int j = 0 ; j< grid[i].size() ; j++){
                int x = i-1;
                int y = j-1;
                
                if(x < 0 && y < 0){
                    continue;
                }
                
                if(y < 0 && x >= 0){
                    grid[i][j] = grid[i][j] + grid[x][j];
                }
                else if(x<0 && y>=0){
                    grid[i][j] = grid[i][j] + grid[i][y];
                }
                else{
                    grid[i][j] = min(grid[i][j] + grid[x][j], grid[i][j] + grid[i][y]);
                }
            }
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};