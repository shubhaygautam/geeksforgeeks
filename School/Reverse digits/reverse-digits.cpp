//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    long long temp = 0;
		long long int reverse_digit(long long int n)
		{
		    // Code here
		    
		    if(n == 0){
		        return temp;
		    }
		    temp = temp*10 + n%10;
		    return reverse_digit(n/10);
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends