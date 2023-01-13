class Solution {
public:
    int trap(vector<int>& height) {
        
        int result = 0;
        pair<int, int> ret = getTrap(height, height.size() - 1);
        
        result += ret.first;
        reverse(height.begin(), height.end());
        result += getTrap(height, height.size() - ret.second - 1).first;
        return result;

    }
    
    pair <int, int> getTrap(vector <int> &height, int sz){
        long minIndex = height[0];
        long minValue = height[0];
        int ret = 0;
        long culSum = 0;
        for(long i = 0 ; i<= sz ; i++){
            if(height[i] >= minValue){
                long temp = ((minValue * (i-minIndex)) - culSum);
                ret += (temp > 0 ? temp : 0);
                minValue = height[i];
                minIndex = i;
                culSum = 0;
            }
            culSum += height[i];
        }
        
        return make_pair(ret, minIndex);
    }
};