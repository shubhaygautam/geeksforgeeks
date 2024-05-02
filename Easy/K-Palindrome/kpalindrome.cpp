//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function*/
bool is_k_palin(string str,int k)
{
//Your code here
    int i = 0; int j = str.size()-1;
        while(i<j){
            if(str[i] != str[j]){
                if(k == 0){
                    return 0;
                }
                k--;
                if(str[i] == str[j-1]){
                    j--;
                    continue;
                }
                else{
                    i++;
                    continue;
                }
            }
            i++;
            j--;
        }
        return 1;
}