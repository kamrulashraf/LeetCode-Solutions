class Solution {
public:
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x = 0, y = 0;
        for(int i = n ; i > 0 ; i-= 2){
            int temp = i-1;
            while(temp--)
                rotatePeriferal(x,y,i, matrix);
            
            x+=1;
            y+=1;
        }
    }
    
    
    void rotatePeriferal(int x, int y, int n, vector<vector<int>>& matrix){
        int cx = x, cy = y;
        bool firstTime = true;
        
        int dirIndex = 0;
        
        int prev = matrix[x][y];
        
        while(true){
            firstTime = false;
            int prevX = cx;
            int prevY = cy;
            cx = cx + dx[dirIndex];
            cy = cy + dy[dirIndex];
            
            if(cx-x >=n || cy-y >= n || cx-x < 0 || cy-y < 0 ){
                cx -= dx[dirIndex];
                cy -= dy[dirIndex];
                
                dirIndex++;
                cx = cx + dx[dirIndex];
                cy = cy + dy[dirIndex];
            }
            
            
            int temp = matrix[cx][cy];
            matrix[cx][cy] = prev;
            prev = temp;
            
            if(cx == x && cy == y)
                break;
        }
    }
};

class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x = 0, y = 0;
        for(int i = n ; i > 0 ; i-= 2){
            rotatePeriferal(x,y,i-1,matrix);
            x+=1;
            y+=1;
        }
    }
    
    
    void rotatePeriferal(int x, int y, int n, vector<vector<int>>& matrix){
        pair<int,int> topRight(x, y+n);
        pair<int,int> bottomRight(x+n, y+n);
        pair<int,int> bottomLeft(x+n,y);
        
        for(int i = 0 ; i< n ; i++){
            int temp = matrix[x][y+i];
            matrix[x][y+i] = matrix[bottomLeft.first-i][bottomLeft.second];
            matrix[bottomLeft.first - i][bottomLeft.second] = matrix[bottomRight.first][bottomRight.second - i];
            matrix[bottomRight.first][bottomRight.second - i] = matrix[topRight.first + i][topRight.second];
            matrix[topRight.first + i][topRight.second] = temp;
        }
    }
};