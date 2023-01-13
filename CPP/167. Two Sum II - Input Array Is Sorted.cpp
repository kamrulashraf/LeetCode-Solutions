class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int>  res;
        
        for(int i = 0 ; i< numbers.size() ; i++){
            int need = target- numbers[i];
            vector<int> :: iterator it = lower_bound(numbers.begin(), numbers.begin() + i , need);
            int index = it - numbers.begin();
            if(index != i && index < numbers.size() &&  numbers[index] == need){
                vector <int> res;
                res.push_back(index+1);
                res.push_back(i+1);
                return res;
            }
            
        }
        
        return res;
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int>  res;
        
        int left = 0;
        int right = numbers.size() - 1;
        
        while(left < right){
            int need = target - numbers[left];
            while(numbers[right] > need){
                right--;
            }
            if(numbers[right] == need && right != left){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            left++;
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res;

        for(int i = 0 ; i< numbers.size() ; i++){
            int need = target-numbers[i];
            
            int pos = lower_bound(numbers.begin() + i + 1, numbers.end(), need) - numbers.begin();
            if(pos < numbers.size() && numbers[pos] == need){
                res.push_back(i+1);
                res.push_back(pos+1);
                break;
            }
        }
        return res;

    }
};