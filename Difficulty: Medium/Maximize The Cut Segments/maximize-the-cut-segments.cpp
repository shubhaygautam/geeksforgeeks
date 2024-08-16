//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int findmaxsegs(int n, int& x, int& y, int& z,vector<int>&memo)
    {
        if(n==0)
        {
            return 0;
        }
        if(memo[n]==-1)
        {
            int minusx=INT_MIN,minusy=INT_MIN,minusz=INT_MIN;
            if(n-x>=0)
            {
                minusx=1+findmaxsegs(n-x,x,y,z,memo);
            }
            if(n-y>=0)
            {
                minusy=1+findmaxsegs(n-y,x,y,z,memo);
            }
            if(n-z>=0)
            {
                minusz=1+findmaxsegs(n-z,x,y,z,memo);
            }
            memo[n]= max(minusx,max(minusy,minusz));
            
        }
        return memo[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>memo(n+1,-1);
        return max(0,findmaxsegs(n,x,y,z,memo));
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends