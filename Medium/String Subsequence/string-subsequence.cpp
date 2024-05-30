//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNum(string s1, int i1 , string s2, int i2,vector<vector<int>>&dp)
    {
        if(i2 == s2.size())
        {
            return 1;
        }
        if(i1 == s1.size())
        {
            return 0;
        }
        
        if(dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }
        
        // Check Is It Equal
        if(s1[i1] == s2[i2])
        {
            return dp[i1][i2] = (countNum(s1,i1+1,s2,i2+1,dp)%1000000007+countNum(s1,i1+1,s2,i2,dp)%1000000007)%1000000007;
        }
        else
        {
            return dp[i1][i2] = countNum(s1,i1+1,s2,i2,dp)%1000000007;
        }
    }
  
    int countWays(string s1, string s2) {
        // code here
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return countNum(s1,0,s2,0,dp); // i1 and i2 are two indexes for string s1 and s2
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends