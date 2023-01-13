class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0, 0,1,-1};
    map< int ,map<int, bool> > visited;
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i< board.size() ; i++){
            for(int j = 0 ; j < board[i].size() ; j++){
                if(word[0] == board[i][j]){
                    visited.clear();
                    int res = dfs(i,j,word,board);
                    if(res){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    
    bool dfs(int x ,int y , string& s, vector< vector<char>>& board){
        bool flag = false;
        if(visited[x][y]){
            return false;
        }
        
        // visited[x][y] = true;

        if(s.size() == 0){
            return true;
        }
        
        if(board[x][y] == s[0]){

            if(s.size() == 1){
                return true;
            }
            string news = s.substr(1);
            visited[x][y] =  true;
            for(int i = 0 ; i< 4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()){
                    if(news.size() && news[0] == board[xx][yy])
                        flag |= dfs(xx,yy,news,board);
                            
                }
            }
            visited[x][y] =  false;

            return flag;
        }
        else{
            return false;
        }
        

    }
};