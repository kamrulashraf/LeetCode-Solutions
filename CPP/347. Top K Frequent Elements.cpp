class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> count;
        priority_queue < pair<int,int> > q; 
        
        for(auto x: nums){
            count[x]++;
            q.push(make_pair(count[x], x));
        }
        
        vector<int> res;
        while(!q.empty()){
            pair<int,int> top = q.top();
            
            if(top.first == count[top.second]){
                res.push_back(top.second);
                k--;
            }
            
            q.pop();
            if(k == 0){
                break;
            }
            
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        priority_queue< pair<int,int> > q;

        int counter =  0;

        for(int i = 0 ;i<nums.size() ; i++){
            counter++;
            if(i+1 < nums.size()){
                if(nums[i] != nums[i+1]){
                    q.push(make_pair(counter, nums[i]));
                    counter = 0;
                }
            }
            else{
                q.push(make_pair(counter, nums[i]));
                counter = 0;
            }
        }

        vector<int> res;
        while(k--){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    
    }
};