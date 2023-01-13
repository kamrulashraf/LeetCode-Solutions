class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalEl = matrix.size();
        if(totalEl > 0){
            totalEl *= matrix[0].size();
        }
        
        int b = 0, e = totalEl;
        
        while(b < e){
            int m = (b+e)/2;
            int row = m/matrix[0].size();
            int col = m%matrix[0].size();
            if(matrix[row][col] < target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        int row = b/matrix[0].size();
        int col = b%matrix[0].size();
        if(b < totalEl && matrix[row][col] == target){
            return true;
        }
        else{
            return false;
        }
    }
};