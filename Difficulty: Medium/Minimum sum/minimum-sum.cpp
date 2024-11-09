//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string addsum(string s1,string s2)
  {
      int i=s1.length()-1;
      int j=s2.length()-1;
      int carry=0;
      string res;
      int sum=0;
      while(i>=0 || j>=0 || carry!=0)
      {
         sum = carry;
         
       if(i>=0)
        {
       sum+=s1[i]-'0';
        i--;
         }
     
     
        if(j>=0)
       {
          sum+=s2[j]-'0';
           j--;
       }
         res.push_back((sum%10 )+'0');
         carry=sum/10;

    
      }
     
  reverse(res.begin(),res.end());
  while(res.length()>1&&res[0]=='0')
  res.erase(res.begin());
      return res;
      
  }
    string minSum(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        string s1="",s2="";
        for(int i=0;i<arr.size();i++)
        {
            if(i%2==0)
            s1+=arr[i]+'0';
            else
            s2+=arr[i]+'0';
            
        }
        
        
        return addsum(s1,s2);
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends