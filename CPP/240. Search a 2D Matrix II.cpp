class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i< matrix.size(); i++){
            bool res = search(matrix[i],target);
            if(res)
                return true;
        }
        return false;
    }
    
    bool search(vector<int>& v, int target){
        
        int b = 0;
        int e = v.size();
        
        while(b<e){
            int m = (b+e)/2;
            if(v[m] < target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        if(b < v.size() && target == v[b]){
            return true;
        }
        else{
            return false;
        }
    }
};