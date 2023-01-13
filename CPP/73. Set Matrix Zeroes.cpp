class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        
        for(int i = 0 ;i< matrix.size() ; i++){
            for(int j = 0 ;j< matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        
        for(auto x: row){
            for(int i = 0 ;i< matrix[x].size() ; i++){
                matrix[x][i] = 0;
            }
        }
        
        for(auto x: col){
            for(int i = 0 ;i< matrix.size() ; i++){
                matrix[i][x] = 0;
            }
        }
        
        return;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool horFirst = false;
        bool verFirst = false;
        

        for(int i = 0 ; i< matrix.size() ; i++){
            if(matrix[i][0] == 0)
                verFirst = true;
        }

        for(int i = 0 ; i< matrix[0].size() ; i++){
            if(matrix[0][i] == 0){
                horFirst = true;
            }
        }

        for(int i = 0 ;i< matrix.size() ; i++){
            for(int j = 0 ;j< matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        
        for(int x = 1 ; x < matrix.size(); x++){
            if(matrix[x][0] == 0){
                for(int i = 0 ;i< matrix[x].size() ; i++){
                    matrix[x][i] = 0;
                }
            }
        }
        
        for(int x = 1 ; x<matrix[0].size() ; x++){
            if(matrix[0][x] == 0){
                for(int i = 0 ;i< matrix.size() ; i++){
                    matrix[i][x] = 0;
                }    
            }
        }

        if(verFirst){
            for(int i = 0 ; i< matrix.size() ; i++){
                matrix[i][0] = 0;
            }
        }
        
        if(horFirst){
            for(int i = 0 ; i< matrix[0].size() ; i++){
                matrix[0][i] = 0;
            }
        }
        
        
        return;
    }
};