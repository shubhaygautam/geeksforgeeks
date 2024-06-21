//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
         string a="",b="",c="",d="";
        int n=str.length();
        int i=0;
        while(i<n && str[i]!='/'){
            a+=str[i];
            i++;
        }
        i++;
        while(i<n && str[i]!=','){
            b+=str[i];
            i++;
        }
        i++;
        while(i<n && str[i]!='/'){
            c+=str[i];
            i++;
        }
        i++;
        while(i<n){
            d+=str[i];
            i++;
        }
        int aint=stoi(a),bint=stoi(b),cint=stoi(c),dint=stoi(d);
        int y=(aint*dint-bint*cint);
        if(y>0){
            return to_string(aint)+"/"+to_string(bint);
        }
        else if(y<0){
            return to_string(cint)+"/"+to_string(dint);
        }
        else return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends