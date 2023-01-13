class Solution {
public:
    
    int mmax[4*100000];
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        makeTree(0,nums.size() - 1, nums, 1);
        
        vector<int> res;
        for(int i = 0 ; i<= nums.size() - k; i++){
            int temp = query(i, i+k-1, 1, 0, nums.size() - 1);
            res.push_back(temp);
        }
        
        return res;
    }
    
    int makeTree(int b , int e, vector<int>& nums, int node){
        
        if(b == e){
            return mmax[node] = nums[b];
        }
        
        int m = (b+e)/2;
        int l = node*2;
        int r = l+1;
        
        int lMax = makeTree(b,m,nums,l);
        int rMax= makeTree(m+1,e,nums,r);
        
        return mmax[node] = max(lMax, rMax);
    }
    
    int query(int l , int r, int node,int b, int e){
        if(b > r || e < l){
            return INT_MIN;
        }
        
        if( b >= l && e<= r){
            return mmax[node];
        }
        
        int m = (b + e)/2;
        int lNode = node*2;
        int rNode = lNode + 1;
        
        int lMax = query(l,r, lNode, b, m);
        int rMax = query(l,r, rNode, m+1, e);
        
        return max(lMax,rMax);
    } 
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue< pair<int,int> > q;
        for(int i = 0 ;i< k-1 ; i++){
            q.push(make_pair(nums[i], i));
        }
        
        
        vector<int> res;
        for(int i = k-1, j = 0; i<nums.size();i++){
            q.push(make_pair(nums[i],i));
            
            while(!q.empty() && q.top().second < j)
                q.pop();
            
            res.push_back(q.top().first);
            j++;
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> dpFromLeft(nums.size() , INT_MIN);
        vector<int> dpFromRight(nums.size() , INT_MIN);
        
        
        int curMax = INT_MIN;
        for(int i = 0 ; i< nums.size() ; i++){
            dpFromLeft[i] = curMax = max(curMax, nums[i]);
            if((i+1)%k == 0){
                curMax = INT_MIN;
            }
        }
        
        curMax = INT_MIN;
        for(int i = nums.size() - 1; i>= 0 ; i--){
            dpFromRight[i] = curMax = max(curMax,nums[i]);
            if(i%k==0)
                curMax = INT_MIN;
        }
        
        vector<int> res;
        
        for(int i = k-1, j = 0 ; i< nums.size() ; i++){
            res.push_back(max(dpFromLeft[i],dpFromRight[j]));
            j++;
        }
        
        return res;
        
        
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque < pair<int,int> > q;
        vector<int> res;
        for(int i = 0 ; i< nums.size() ; i++){
            while(!q.empty() && q.front().second <= i-k)
                q.pop_front();
            
            while(!q.empty() && q.back().first < nums[i])
                q.pop_back();
            
            
            
            q.push_back(make_pair(nums[i], i));
            
            if(i >= k-1)
                res.push_back(q.front().first);
        }
        
        return res;
    }
};