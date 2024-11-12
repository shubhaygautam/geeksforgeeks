//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        int n=arr.size();
        int m =arr[0].size();
    
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mini=min(mini,arr[i][j]);
                maxi=max(maxi,arr[i][j]);
            }
        }
         vector<int> b(maxi+1,0);
         //initialize till mini-1 to 1 ;
         for(int i=0;i<mini;i++)b[i]=1;
         for(int i=0;i<n;i++){
             vector<int>temp=arr[i];
             int lo=arr[i][0];
             int up=arr[i][1];
             for(int j=lo ;j<up;j++){
                 if(b[j]==1)return false;
                 
                 b[j]=1;
             }
         }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends