//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int res = 0, diff = INT_MAX, n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n-2;i++){
            int low = i+1, high = n-1;
            while(low < high){
                int sum = arr[i] + arr[low] + arr[high];
                if(sum == target) return target;
                else if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    res = sum;
                }
                else if(abs(sum - target) == diff){
                    res = max(res, sum);
                }
                
                if(sum < target) low++;
                else high--;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends