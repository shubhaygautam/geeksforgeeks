//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    int rev(long long n, long long temp){
        if(n == 0){
            return temp;
        }
        temp = (temp*10) + (n%10);
        return rev(n/10, temp);
    }
    
    bool ispalin(long long n){
        int x = rev(n, 0);
        if(n == x){
            return 1;
        }
        return 0;
    }
  
    long long isSumPalindrome(long long n){
        // code here
        int i = 6;
        // long long x = n;
        while(i--){
            if(ispalin(n)){
                return n;
            }
            n += rev(n,0);
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution ob;
        cout<<ob.isSumPalindrome(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends