// search with sliding window

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left, right;
    
        if(k == arr.size()){
            return arr;
        }
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        if(inRange(pos, arr.size()) && arr[pos] != x){
            if( pos-1 >= 0 && abs(arr[pos-1]-x) <= abs(arr[pos]-x)){
                pos--;
            }
        }
        
        
        if(!inRange(pos, arr.size())){
            pos--;
        }
        
        if(k == 1){
            left = right = pos;
        }
        else if(inRange(pos-1, arr.size()) && (( inRange(pos+1, arr.size()) && getAbsVal(arr[pos-1], x) <= getAbsVal(arr[pos+1],x) ) || !inRange(pos+1, arr.size())) ){
            left = pos - 1;
            right = pos;
        }
        else{
            left = pos;
            right = pos+1;
        }
        
        
        
        while(right - left + 1 < k){
            if(inRange(left-1, arr.size()) && ((inRange(right+1, arr.size()) && getAbsVal(arr[left-1], x) <= getAbsVal(arr[right+1], x) || !inRange(right+1, arr.size())))){
                left--;
            }
            else{
                right++;
            }
        }
        vector <int> res;
        for(int i = left ;i  <= right; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
    
    bool inRange(int i, int length){
        if(i >= 0 && i < length){
            return true;
        }
        return false;
    }
    
    int getAbsVal(int val, int x){
        return abs(val-x);
    }
};

// via sorting array
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        merge(arr,0,arr.size()-1,x);
        vector<int> res(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
    
    
    void merge(vector<int> &arr, int b , int e, int x){
        int m = (b+e)/2;
        if(b == e){
            return;
        }
        merge(arr, b, m, x);
        merge(arr, m+1, e, x);
        
        mergeArr(arr,b,m,e, x);
    }
    
    void mergeArr(vector<int> &arr, int b, int m , int e, int x){

        vector<int> left, right;
        
        for(int i = b ; i<= m; i++){
            left.push_back(arr[i]);
        }
        
        for(int i = m+1 ; i<= e; i++){
            right.push_back(arr[i]);
        }
        int l = 0;
        int r = 0;
        
        int it = b;
        while(l < left.size() || r< right.size()){
            if(r >= right.size()){
                arr[it++] = left[l++];
                continue;
            }
            if(l >= left.size() ){
                arr[it++] = right[r++];
                continue;
            }
            
            if( abs(left[l]-x) <= abs(right[r]-x)){
                arr[it++] = left[l++];
            }
            else{
                arr[it++] = right[r++];
            }
        }
    }
};
    
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int b = 0;
        int e = arr.size() - k;
        
        while(b < e){
            int m = (b+e)/2;
            if(abs(arr[m] - x) >  abs(arr[m+k] - x ) || (arr[m] == arr[m+k] && arr[m+k] <= x)){ // for checking upper bound if test case is like 1 2 2 2 2 2 2 3 3 3
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        vector<int> res(arr.begin() + b, arr.begin() +b + k);
        return res;
    }
};