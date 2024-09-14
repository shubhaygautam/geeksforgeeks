//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> posarr;
	    vector<int> negarr;
	    for(int i=0 ;i<arr.size() ;i++)
	    {
	        if(arr[i]<0){
	            negarr.push_back(arr[i]);
	        }else{
	            posarr.push_back(arr[i]);
	        }
	    }
	    int p=0,ne=0,i=0;
	    while(i<arr.size())
	    {
	        if(p!=posarr.size()){
	            arr[i++] = posarr[p++];
	        }
	        if(ne!=negarr.size()){
	            arr[i++] = negarr[ne++];
	        }
	    }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends