class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int ,int > hash;
        for(int i = 0 ; i< arr.size() ; i++){
            int temp = 2*arr[i];
            if(hash[temp] != 0){
                return true;
            }
            
            if(arr[i]%2 == 0){
                temp = arr[i]/2;
                if(hash[temp] != 0){
                    return true;
                }
            }
            hash[arr[i]] = 1;
        }
        
        return false;
    }
};