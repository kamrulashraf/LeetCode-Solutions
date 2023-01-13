class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;

        for(int i = 0 ; i< 32 ; i++){
            
            int bit = (1<<i);
            
            int counter = 0;
            
            for(int j = 0 ; j< nums.size() ; j++){
                if( (nums[j]&bit) > 0){
                    counter++;
                }
                if(counter > nums.size()/2){
                    res |= bit;
                }
            }
            
        }
        
        return res;
    }
};

// moore algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int selected = nums[0];
        int counter = 0;
        for(auto x: nums){
            if(x == selected)
                counter++;
            else{
                counter--;
            }
            
            if(counter == 0){
                selected = x;
                counter++;
            }
        }
        
        return selected;
        
    }
};