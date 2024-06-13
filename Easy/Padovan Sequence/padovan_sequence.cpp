
class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        
        if(n<3) return 1;
        int mod = 1e9 + 7;
        
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = dp[2] = 1;
        
        for(int i = 3; i<=n; i++){
            dp[i] = (dp[i-2]%mod + dp[i-3]%mod) % mod ;
        }
        return dp[n];
    }
};
