//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int dp[10][26];

    int mat[4][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9},
                     {-1,0,-1}};
    
    bool isValid(int x,int y){
        if(x < 0 || x >= 4 || y < 0 || y >= 3) return (false);
        if(mat[x][y] == -1) return (false);
        return (true);
    }
    
    long long int helper(int x,int y,int n){
        if(n == 1) return (1);
        if(dp[mat[x][y]][n] != -1) return dp[mat[x][y]][n];
        
        int dx[] = {0,-1,0,1,0};
        int dy[] = {0,0,1,0,-1};
        
        long long int cnt = 0;
        for(int i = 0; i < 5; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx,ny)){
                cnt += helper(nx,ny,n-1);
            }
        }
        
        return (dp[mat[x][y]][n] = cnt);
    }
    
    long long getCount(int N){
     dp[10][N+1];
     memset(dp,-1,sizeof(dp));
     long long int ans = 0;
     for(int i = 0; i < 4; i++){
         for(int j = 0; j < 3; j++){
             if(mat[i][j] != -1)
                 ans += helper(i,j,N);
         }
     }
     return (ans);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends