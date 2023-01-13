class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        vector<int> dp(n+1,INT_MAX);
        for(int i = 1 ; i*i <= n; i++){
            sq.push_back(i*i);
            dp[i*i] = 1;
        }
        
        
        for(int i = 1 ; i<= n; i++){
            for(auto x: sq){
                int temp = i-x;
                if(temp <= 0){
                    break;
                }
                dp[i] = min(dp[i], dp[temp] +1);
            }
        }
        
        return dp[n];
        
        
    }
};