//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int, pair<int, int>>> diff;
        for (int i = 0; i < n; ++i) {
            diff.push_back({abs(arr[i] - brr[i]), {arr[i], brr[i]}});
        }
    
        sort(diff.begin(), diff.end(), greater<pair<int, pair<int, int>>>());
    
        long long maxi = 0;
        for (int i = 0; i < n; ++i) {
            int a_tip = diff[i].second.first;
            int b_tip = diff[i].second.second;
            if (x > 0 && (y <= 0 || a_tip >= b_tip)) {
                maxi += a_tip;
                x--;
            } else {
                maxi += b_tip;
                y--;
            }
        }
    
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends