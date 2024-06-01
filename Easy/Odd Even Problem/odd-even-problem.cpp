//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
         vector<int> freq(26,0);
        for(auto &c: s)
            freq[c-'a']++;
        int ans=0;
        for(int i=1; i<=26; i++)
        {
            if(freq[i-1]==0)
            continue;
            if((i%2) ^ (freq[i-1]%2) == 0)
                ans++;
        }
        if(ans % 2 != 0)return "ODD";
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends