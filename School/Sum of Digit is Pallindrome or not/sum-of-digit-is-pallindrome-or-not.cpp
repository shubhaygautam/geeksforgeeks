//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int sum_of(int n){
        if(n == 0){
            return 0;
        }
        return (n%10 + sum_of(n/10));
    }
    
    int rev(int n, int temp){
        if(n == 0){
            return temp;
        }
        temp = (temp*10) + (n%10);
        return rev(n/10, temp);
    }
  
    int isDigitSumPalindrome(int n) {
        // code here
        int x = sum_of(n);
        int y = rev(x, 0);
        if(x == y) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends