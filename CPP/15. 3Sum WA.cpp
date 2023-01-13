class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map < int, list<int> > mark;
        vector < vector<int> > result;
        
        for(int i = 0 ; i< nums.size() ; i++){
            mark[nums[i]].push_back(i);
        }
        
        int numSZ = nums.size();
        for(int i = 0 ; i< numSZ ; i++){
            int ithEl = nums[i];
            for(int j = i+1 ; j< numSZ ; j++){
                int jthEl = nums[j];
                int needEl = - (ithEl + jthEl);
                for(list<int>:: iterator it = mark[needEl].begin() ; it != mark[needEl].end() ; it++){
                    if(*it > j){
                        vector <int> temp;
                        temp.push_back(ithEl);
                        temp.push_back(jthEl);
                        temp.push_back(needEl);
                        mark[needEl].erase(it);
                        result.push_back(temp);
                    }
                } 
            }
        }
        
        return result;
    }
}; 