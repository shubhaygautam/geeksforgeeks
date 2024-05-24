//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 && arr[0]==0)  return 2;
            if(target==0||target==arr[0])   return 1;
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int notTaken=solve(ind-1,target,arr,dp);
        int taken=0;  
        if(arr[ind]<=target)
            taken=solve(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=(notTaken+taken)%1000000007;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int mod = 1e9+7;
        long long total=0;
        for(int i=0; i<n; i++){
            total+=arr[i];
        }
        if(total-d<0||(total-d)%2==1){
            return 0;
        }
        long long sum=(total-d)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        //return f(n-1,sum,arr,dp);
        for(int i = 0; i<sum+1; i++){
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1; i<n+1; i++){
            for(int j = 0; j < sum + 1; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j]%mod + dp[i-1][j - arr[i-1]]%mod;
                }
                else dp[i][j] = dp[i-1][j]%mod;
            }
        }
        return dp[n][sum]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends