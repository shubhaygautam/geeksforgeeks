//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
     int n = arr.size();
        sort(arr.begin(),arr.end());
        int cnt = 0;
        for(int i=0;i<n;i++){
            
            if(i == n-1){
               if(arr[i] == arr[i-1]){
                   cnt++;
                    if(cnt % 2 !=0) return arr[i];
               }else{
                   return arr[i];
               }
            }
            
            if(arr[i]==arr[i+1]){
                cnt++;
            }
            else if(arr[i] != arr[i+1]){
                cnt++;
                if(cnt%2 !=0) return arr[i];
                cnt=0;
            }
            
        }
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
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends