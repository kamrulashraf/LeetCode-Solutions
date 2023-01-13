class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int b = 0 , e = arr.size();
        
        while(b  < e){
            int m = (b+e)/2;
            
            if(missingElement(arr,m) < k){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        if(b == 0){
            return k;
        }
        else{
            return arr[b-1] + (k - missingElement(arr,b-1));
        }
    }
    
    int missingElement(vector<int> arr, int m){
        return arr[m] - m - 1;
    }
};