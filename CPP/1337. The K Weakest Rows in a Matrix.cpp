class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector < pair<int,int> > savedEl;
        int index = 0;
        for(auto row : mat){
            int pos = lowerBound(row);
            savedEl.push_back(make_pair(pos+1,index));
            index++;

        }
        
        vector <int> res;
        sort(savedEl.begin(), savedEl.end());
        
        for(int i = 0 ; i < k ; i++){
            res.push_back(savedEl[i].second);
        }
        
        
        return res;
    }
    
    
    int lowerBound(vector<int> arr){
        int b = 0, e = arr.size();
        while(b < e){
            int m = (b+e)/2;
            if(arr[m] == 1){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b-1;
    }
};