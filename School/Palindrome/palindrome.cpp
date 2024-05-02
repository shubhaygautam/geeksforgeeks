//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
	
	    int rev(int n, int temp){
	        if(n == 0){
	            return temp;
	        }
	        temp = temp*10 + n%10;
	        return rev(n/10, temp);
	    }
	
		string is_palindrome(int n)
		{
		    // Code here.
		    int y = rev(n, 0);
		    if(n == y){
		        return "Yes";
		    }
		    return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends