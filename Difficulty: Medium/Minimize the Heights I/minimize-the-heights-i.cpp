//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
          int output = INT_MAX;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> premin(n+1); int epremin = arr[0]+k;
        vector<int> postmin(n+1); int epostmin = arr[n-1]-k; postmin[n] = INT_MAX;
        vector<int> premax(n+1); int epremax = arr[0]+k;
        vector<int> postmax(n+1); int epostmax = arr[n-1]-k; postmax[n] = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            epremin = epremin < (arr[i]+k) ? epremin : (arr[i]+k);
            epostmin = epostmin < (arr[n-1-i]-k) ? epostmin : (arr[n-1-i]-k);
            epremax = epremax > (arr[i]+k) ? epremax : (arr[i]+k);
            epostmax = epostmax > (arr[n-1-i]-k) ? epostmax : (arr[n-1-i]-k);
            
            premin[i] = epremin;
            postmin[n-1-i] = epostmin;
            premax[i] = epremax;
            postmax[n-1-i] = epostmax;
        }
        
        for(int start=0; start<n; start++)
        {
            int emin = premin[start] < postmin[start+1] ? premin[start] : postmin[start+1];
            int emax = premax[start] > postmax[start+1] ? premax[start] : postmax[start+1];
            output = output < (emax - emin) ? output : (emax - emin);
        }
        
        return output;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends