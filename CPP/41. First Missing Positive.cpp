class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        string s(nums.size() + 2, '0');
        for(auto x: nums){
            if(x > 0 && x <= nums.size()){
                s[x] = '1';
            }
        }
        
        cout << s << endl;
        for(int i = 1 ; i<= nums.size()+1 ; i++){
            if(s[i] == '0'){
                return i;
            }
        }
        
        return 0;
    }
};