class Solution {
public:
    struct comp{
        bool operator()(const vector<int> &a,const vector<int>& b){
            return a[0] < b[0];
        }
    };
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        int mmax = 0;
        for(int i = 0 ; i<intervals.size() ; i++){
            if(intervals[i][0] < mmax){
                return false;
            }
            mmax = max(mmax, intervals[i][1]);
        }

        return true;
    }
};