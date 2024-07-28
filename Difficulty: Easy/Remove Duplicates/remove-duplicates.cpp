//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
         string s="";

// declare a map of char and int which count the apperance of char (a to z) 
        map<char,int> mp;
        for(int i=0;i<str.size();i++){
            char ch = str[i];

// if this character ch appers first time add it to the string s
            if(mp[ch]==0) s+= str[i];

// increasing the count of that character ch
            mp[ch]++;
        }
        return s;
    
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends