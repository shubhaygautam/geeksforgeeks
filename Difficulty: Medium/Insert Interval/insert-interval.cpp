//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
         intervals.push_back(newInterval);
        int n = intervals.size();
        
        sort(begin(intervals),end(intervals));
        
        int st = intervals[0][0];
        int ed = intervals[0][1];
        
        vector<vector<int>> result;
        
        for(int i=1; i<n; i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            if(ed >= s) {
                st = min(st,s);
                ed = max(ed,e);
            }
            else{
                result.push_back({st,ed});
                st = s;
                ed = e;
            }
        }
        
        result.push_back({st,ed});
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends