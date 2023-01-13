class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter = 0, e = 0;
        if(grid.size() > 0){
            e = grid[0].size();
        }
        for(int i = 0 ; i< grid.size() ; i++){
            int pos = lowerBound(grid[i], e);
            counter += (e - pos - 1) * (grid.size() - i);
            e = pos+1;
        }
        return counter;
        
    }
    
    
    int lowerBound(vector <int> arr, int e){
        int b = 0;
        while(b < e){
            int m = (b+e)/2;
            if(arr[m] >= 0){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b-1;
    }
};