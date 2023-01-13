class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int x = newInterval[0];
        int y = newInterval[1];
        bool flag = true;
        vector<vector<int>> res;
        for(int i = 0 ;i< intervals.size() ; i++){
            int xx = intervals[i][0];
            int yy = intervals[i][1];
            if(!flag){
                res.push_back(intervals[i]);
                continue;
            }

            if(yy < x){
                res.push_back(intervals[i]);
                continue;
            }

            if(y < xx){
                flag = false;
                res.push_back(vector<int> {x,y});
                res.push_back(intervals[i]);
                continue;
            }

            if( (x < xx && y >= x) || (x >= xx && x <= yy)){
                flag = false;
                int left = min(x, xx);
                while(i+1 < intervals.size() && intervals[i+1][0] <= y){
                    i++;
                }
                int right = max(intervals[i][1], y);
                res.push_back(vector<int> {left, right});
            }
        }

        if(flag){
            res.push_back(newInterval);
        }
        return res;
    }
};