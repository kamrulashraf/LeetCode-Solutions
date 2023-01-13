class Solution {
public:
    struct Node{
        int val;
        int prop;
    };
    
    Node tree[3*1000002];
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        init();
        int mmax = INT_MIN;
        int result = mmax;
        
        for(int i = 0 ; i< intervals.size() ; i++){
            mmax = max(mmax, intervals[i][1]);
        }
        for(int i = 0 ; i< intervals.size() ; i++){
            update(0, mmax, 1, intervals[i][0], intervals[i][1]-1, 1);
        }
        result = calculateRes(0, mmax, 1, 0);
        return result;
    }
    
    
    void init(){
        for(int i = 0 ; i<= 3000002 ; i++){
            tree[i].val = 0;
            tree[i].prop = 0;
        }
    }
    void update(int b ,int e, int node, int left, int right, int val){
        if(b > right || e < left){
            return;
        }
        
        if(b >= left && e <= right){
            tree[node].prop += val;
            return;
        }
        
        int m = (b+e)/2;
        int leftNode = node*2;
        int rightNode = leftNode + 1;
        update(b, m , leftNode, left, right, val);
        update(m+1, e, rightNode, left, right, val);
    }
    
    int calculateRes(int b, int e, int node, int carry){
        if(b == e){
            return tree[node].prop + carry;
        }
        int m = (b+e)/2;
        int leftNode = node*2;
        int rightNode = leftNode+1;
        int l = calculateRes(b,m, leftNode, carry + tree[node].prop);
        int r = calculateRes(m+1, e, rightNode, carry + tree[node].prop);
        return max(l ,r);
    }
};


class Solution1 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int result = 0;
        priority_queue <int, vector<int> , greater <int> > q;
        for(int i = 0 ; i< intervals.size() ; i++){
            if(q.size() == 0){
                q.push(intervals[i][1]);
            }
            else{
                int top = q.top();
                if(top <= intervals[i][0]){
                    q.pop();
                }
                q.push(intervals[i][1]);
            }
            
            result = max(result, (int) q.size());
        }
        
        
        return result;
    }
    
     static bool comp(vector<int> a, vector<int> b){
        return a[0] <= b[0];
    }
};

class Solution {
public:
    struct comp{
        bool operator()(const vector<int>& a, const vector<int>&b){
            return a[1] >= b[1];
        }
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue< vector<int> , vector< vector<int>> , comp> q;
        sort(intervals.begin(), intervals.end());
        int res = 0;
        for(int i = 0 ; i< intervals.size() ; i++){
            if(q.size() > 0){
                vector<int> top = q.top();
                int x = intervals[i][0];
                int y = intervals[i][1];
                
                if(top[1] <= x){
                    q.pop();
                }
                q.push(intervals[i]);
            }
            else{
                q.push(intervals[i]);
            }
            res = max(res, (int) q.size());
        }

        return res;
    }
};

class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector <int> a,b;
        
        for(int i = 0 ; i< intervals.size() ; i++){
            a.push_back(intervals[i][0]);
            b.push_back(intervals[i][1]);
        }
        
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int endTimePointer = 0;
        
        int result = 0;
        for(int i = 0 ; i< a.size() ; i++){
            if(a[i] >= b[endTimePointer]){
                endTimePointer++;
            }
            else{
                result++;
            }
        }
        
        return result;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> s, e;
        for(int i = 0 ; i< intervals.size(); i++){
            s.push_back(intervals[i][0]);
            e.push_back(intervals[i][1]);
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int j = 0, res = 0;
        for(int i = 0 ; i< s.size() ; i++){
            while(j < e.size() && e[j] <= s[i]){
                j++;
            }
            
            int curRoom = i-j+1;
            res = max(res, curRoom);
        }

        return res;
    }
};


class Solution {
public:
    int tree[1000004] = {0};
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int mmax = 0;
        for(int i = 0 ; i< intervals.size() ; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            x++;
            y++;
            update(x+1,1);
            update(y+1, -1);
            mmax = max(mmax,max(x, y));
        }


        int res = 0;
        for(int i = 0 ; i<= mmax; i++){
            res = max(res,getSum(i));
        }

        return res;


    }

    int getSum(int indx){
        int ret = 0;
        while(indx){
            ret += tree[indx];
            indx -= indx & -indx;
        }
        return ret;
    }

    void update(int indx, int val){
        int n = 1000003;
        while(indx <= n){
            tree[indx] += val;
            indx += indx & -indx;
        }
    }
};