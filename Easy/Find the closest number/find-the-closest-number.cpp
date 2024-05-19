//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        vector<int>ans;
        
        int res = INT_MIN;
        
        for(int i = 0 ; i < n ; i++)
        {
            int diff = abs(arr[i] - k);
            
            ans.push_back(diff);
        }
        
        int mini = *min_element (ans.begin() , ans.end());
        
        for(int i = 0 ; i < n ; i++)
        {
            if(ans[i] == mini)
            {
                res = max(res , arr[i]);
            }
        }
        
        return res;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends