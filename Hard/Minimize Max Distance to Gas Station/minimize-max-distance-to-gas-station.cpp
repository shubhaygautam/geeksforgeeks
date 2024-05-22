//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(vector<int> &stations, int K,double ans){
      int cnt=0;
      for(int i=1;i<stations.size();i++){
          double diff=(double)stations[i]-(double)stations[i-1];
          if(diff>ans){
              double k=fmod(diff,ans);
              cnt+=diff/ans;
              
              if(k==0)cnt--;
            
          }
      }
      if(cnt>K)return false;
      
      return true;
  }
    double findSmallestMaxDist(vector<int> &stations, int K){
     
      int n=stations.size();
      double  l=0;
      double h=stations[n-1]-stations[0];
     
      double ans=0.0;
      while(l<=h){
          double mid=(l+h)/2;
         
          if(check(stations,K,mid)){
              h=mid-0.000001;
              ans=mid;
          }

         else l=mid+.000001;
          
      }
      
      
      return ans;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends