//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string s="";
        for(int i=0;i<arr.size();i++){
            if(s.length()<arr[i].length()) s=arr[i];
        } 
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<s.length();j++)
            if(s[j]!=arr[i][j]) s.erase(j,s.length());
        }
        if(s.length()==0) s="-1";
        return s;
    }
   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends