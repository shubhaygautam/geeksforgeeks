//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxCount = 0;
        int buyPrice = prices[0];
        for(int i = 1;i<prices.size();i++) {
            if(prices[i] > buyPrice) {
                maxCount =  max(prices[i] - buyPrice,maxCount);
            } else {
                buyPrice =  prices[i];
            } 
        }
        
        return maxCount;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends