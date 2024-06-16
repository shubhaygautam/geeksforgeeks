//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int x){
        if(x == 1 or x == 0){
            return false;
        }
        for(int i = 2; i<=sqrt(x); i++){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
  
    vector<int> getPrimes(int n) {
        // code here
        for(int i = 2; i<n; i++){
            if(isPrime(i) && isPrime(n-i)){
                return {min(i,n-i), max(i,n-i)};
            }
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends