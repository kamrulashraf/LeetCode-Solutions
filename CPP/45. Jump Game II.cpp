class Solution {
public:
    
    std:: vector<int> tree;
    
    int jump(vector<int>& nums) {
        tree = vector<int> (40001, INT_MAX);
        int sz = nums.size() - 1;
        update(0, sz, sz, 1, 1);
        
        
        for(int i = sz-1; i>=0;i--){
            int b = i;
            int e = i+nums[i];
            
            int res = query(0,sz,b,e,1);
            res = (res == INT_MAX)? INT_MAX : res+1;
            update(0,sz,i,1,res);
        }
        
        return query(0,sz,0,0,1)-1 ;
        
        
    }
    
    
    void update(int b,int e, int i, int node, int val){
        
        if(b > i || e < i){
            return;
        }
        
        if(b == e && b == i){
            tree[node] = val;
            return;
        }
        int m = (b+e)/2;
        int left = node*2;
        int right = left+1;
        
        update(b,m,i,left,val);
        update(m+1,e,i,right,val);
        
        tree[node] = min(tree[left], tree[right]);
        
    }
    
    
    int query(int b, int e, int l, int r,int node){
        if(b > r || e < l){
            return INT_MAX;
        }
        
        if( b >= l && e <= r){
            return tree[node];
        }
        
        int m = (b+e)/2;
        int left = node*2;
        int right = left+1;
        
        int lval = query(b,m,l,r,left);
        int rval = query(m+1, e, l, r, right);
        
        return min(lval, rval);
    }
};