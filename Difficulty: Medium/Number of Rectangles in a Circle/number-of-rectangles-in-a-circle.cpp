//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int cnt = 0;
        int diameter = 2*r;
        int diameter_sq = pow(diameter, 2);
        for(int i = 1; i<diameter; i++){
            for(int j = 1; j<diameter; j++){
                int diagonal_len_sq = (i*i + j*j);
                if(diagonal_len_sq<=diameter_sq){
                    cnt++;
                }
            }
        }
        return cnt;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends