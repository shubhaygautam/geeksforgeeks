//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &a) {
        // Complete the function
        vector<int>ans(a.size());
        int j=0;
       for(int i=0;i<a.size()-1;i++){
           
           if(a[i]==0)continue;
           if(a[i]!=a[i+1]){ans[j++]=a[i];continue;}
         
           a[i]*=2;
           ans[j++]=a[i];
           a[i+1]=0;
       }
    ans[j]=a[a.size()-1];
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends