//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     string roundToNearest(string N) 
    { 
        int n=N.size();
        int carry;
        //if last digit is less than equal to 5
        if(N[n-1]<='5'){
            N[n-1]='0';
            return N;
        }else{
            N[n-1]='0';
            carry=1;
        }
        
        for(int i=n-2;i>=0 && carry==1;i--){
            int digit=N[i]-'0';
            digit++;
            carry=0;
            if(digit==10){
                digit=0;
                carry=1;
            }
            N[i]=digit+'0';
        }
        
        if(carry)
          N="1"+N;
        
        return N;
    }  
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends