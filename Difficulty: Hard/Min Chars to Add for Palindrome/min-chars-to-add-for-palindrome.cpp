//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
         int n = s.size();
        string rev_s = s; 
        reverse(rev_s.begin(), rev_s.end());

        string combined = s + '#' + rev_s; // Combine original string, separator, and reversed string
        int m = combined.size();

        // Compute the LPS (Longest Prefix Suffix) array
        vector<int> lps(m, 0);
        for (int i = 1; i < m; i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }

        // Minimum characters to add
        return n - lps[m - 1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends