class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums,0, nums.size() -1);
        reverse(nums.begin(), nums.end());
        return nums[k-1];
    }
    
    void quickSort(vector<int>&v, int b ,int e){
        
        if(b >= e){
            return;
        }
        
        
        int pivot = v[e];
        
        int prev = b-1;
        
        for(int i = b; i < e; i++){
            if(v[i] < pivot){
                prev++;
                swap(v[prev], v[i]);
            }
        }
        
        prev++;
        swap(v[prev], v[e]);
        
        quickSort(v, b, prev-1);
        quickSort(v, prev+1, e);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0, nums.size() -1, nums.size() - k);
    }
    
    int quickSelect(vector<int>&v, int b ,int e, int nth){
        int rand  = b + rand%(e-b+1);
        swap(v[e],v[rand]);
        int pivot = v[e];
        
        int prev = b-1;
        
        for(int i = b; i < e; i++){
            if(v[i] < pivot){
                prev++;
                swap(v[prev], v[i]);
            }
        }
        
        prev++;
        swap(v[prev], v[e]);
        if(nth < prev)
            return quickSelect(v, b, prev-1, nth);
        else if(nth > prev)
            return quickSelect(v, prev+1, e, nth);
        else
            return v[prev];
        
    }
};

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int , vector<int> , greater<int> >  q;
    
    for(auto x: nums){
        q.push(x);
        if(q.size() > k){
            q.pop();
        }
    }
    
    return q.top();
}