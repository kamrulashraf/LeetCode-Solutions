class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack < pair<int,int> > st;

        st.push( make_pair( 0, -1));
        long long res = 0;
        for(int i = 0; i < heights.size() ; i++){
            int cur = heights[i];
            
            while(st.top().second != -1 && st.top().first > cur){
                pair<int,int> top = st.top();
                st.pop();
                long long area = (i - st.top().second-1) * top.first;
                res = max(res, area);
            }
            
            st.push(make_pair(cur, i));
        }
        
        return res;
    }
};