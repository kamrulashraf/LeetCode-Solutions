class Solution {
public:
    int dp[101];
    int numDecodings(string s) {
        memset(dp,-1, sizeof(dp));
        return getCount(s,0);
    }

    int getCount(string &s, int i){
        if(i == s.size()){
            return 1;
        }

        if(dp[i] != - 1)
            return dp[i];

        int res  = 0;

        if(stoi(s.substr(i,1)) == 0)
            return 0;
        res += getCount(s,i+1);

        if(i < s.size() - 1){
            string temp = s.substr(i,2);
            int tmpInt = stoi(temp);
            if(tmpInt <= 26){
                res += getCount(s, i+2);
            }
        }
        return dp[i] = res;

    }
};