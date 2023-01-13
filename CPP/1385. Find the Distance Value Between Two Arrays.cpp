class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int counter = 0;
        
        sort(arr2.begin(), arr2.end());
        for(int i = 0 ; i < arr1.size() ; i++){
            int low = arr1[i] - d;
            int high = arr1[i] + d;
            
            int lowIndex = lowerBound(arr2, low);
            if(! (arr2[lowIndex] <= high && arr2[lowIndex] >= low)){
                counter++;
            }
        }
        
        return counter;
    }
    
    int lowerBound(vector<int> &arr, int target){
        int b = 0 , e = arr.size();
        while(b < e){
            int m = (b+e)/2;
            if(arr[m] < target){
                b = m+1;
            }
            else{
                e = m;
            }
        }
        
        return b;
    }
    
    
};