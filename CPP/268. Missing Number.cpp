class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0 , y = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            x ^= i;
            y ^= nums[i];
        }

        x ^= nums.size();
        
        return x^y;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        string s(nums.size()+1, '0');

        for(auto x: nums){
            s[x] = '1';
        }

        for(int i = 0 ; i<=nums.size() ; i++){
            if(s[i] == '0')
                return i;
        }

        return 0;
    }
};