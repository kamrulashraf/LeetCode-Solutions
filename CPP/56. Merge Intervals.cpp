#include <bits/stdc++.h>
class Solution {
public:
    struct comp{
        inline bool operator()(const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        
        int newS = intervals[0][0];
        int curMax = intervals[0][1];
        vector < vector<int> > ret;
        
        for(int i = 0 ; i< intervals.size() ; i++){
            int secondEl = intervals[i][1];
            int firstEl = intervals[i][0];
            if(firstEl > curMax){
                vector <int> temp{newS, curMax};
                ret.push_back(temp);
                newS = firstEl;
            }
            curMax = max(secondEl, curMax);

        }
        vector <int> lastPush{newS, curMax};
        ret.push_back(lastPush);
        
        return ret;
    }
};


class Solution {
public:

    struct comp{
      bool operator()(const vector<int>&a, const vector<int> &b){
          return a[0] < b[0];
      }  
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        vector<vector<int>> res;
        for(int i = 0 ; i<intervals.size() ; i++){
            cout << intervals[i][0] << endl;
            int save = i;
            int mmax = intervals[i][1];

            while(i < intervals.size() && intervals[i][0] <= mmax){
                mmax = max(mmax, intervals[i][1]);
                i++;
            }
            i--;
            res.push_back(vector<int> {intervals[save][0], mmax});
        }

        return res;

    }
};