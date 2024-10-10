//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
          map<int, vector<int>>m;
        for(int i=0; i<arr.size(); i++){
            m[arr[i]].push_back(i);
        }
        
        int maxxi=0;
        
        for(auto i: m){
             int n=i.second.size();
             maxxi=max(maxxi, i.second[n-1]-i.second[0]);
        }
        
        return maxxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends