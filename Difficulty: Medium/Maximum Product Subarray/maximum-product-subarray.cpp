//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int leftproduct=1,rightproduct=1;
         int ans=INT_MIN;
         for(int i=0;i<arr.size();i++)
         {
             leftproduct*=arr[i];
             rightproduct*=arr[arr.size()-1-i];
             ans=max({ans,leftproduct,rightproduct});
             if(leftproduct==0)
             {
                 leftproduct=1;
             }
             if(rightproduct==0)
             {
                 rightproduct=1;
             }
             
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends