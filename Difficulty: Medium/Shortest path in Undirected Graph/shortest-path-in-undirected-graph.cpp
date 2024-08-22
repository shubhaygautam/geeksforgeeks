//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> ans(N, -1);
        ans[src] = 0;
        
        vector<vector<int>> adj(N, vector<int>());
        for(auto i : edges) {
            int s = i[0], e = i[1];
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        
        while(!pq.empty()) {
            int curr = pq.top().second;
            int curr_weight = pq.top().first;
            pq.pop();
            
            for(auto i : adj[curr]) {
                if(ans[i] == -1 || ans[i] > curr_weight + 1) {
                    pq.push({curr_weight + 1, i});
                    ans[i] = curr_weight + 1;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends