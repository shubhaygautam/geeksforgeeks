//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        if (n == 0) return 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> componentSize(n, vector<int>(n, 0));
        int componentId = 2; 
        unordered_map<int, int> sizeMap;

        function<int(int, int, int)> dfs = [&](int x, int y, int id) {
            if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y] || grid[x][y] == 0)
                return 0;
            visited[x][y] = true;
            componentSize[x][y] = id;
            int size = 1;
            size += dfs(x + 1, y, id);
            size += dfs(x - 1, y, id);
            size += dfs(x, y + 1, id);
            size += dfs(x, y - 1, id);
            return size;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int size = dfs(i, j, componentId);
                    sizeMap[componentId] = size;
                    ++componentId;
                }
            }
        }

        int maxConnected = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> neighborComponents;
                    if (i > 0 && grid[i - 1][j] == 1) neighborComponents[componentSize[i - 1][j]]++;
                    if (i < n - 1 && grid[i + 1][j] == 1) neighborComponents[componentSize[i + 1][j]]++;
                    if (j > 0 && grid[i][j - 1] == 1) neighborComponents[componentSize[i][j - 1]]++;
                    if (j < n - 1 && grid[i][j + 1] == 1) neighborComponents[componentSize[i][j + 1]]++;

                    int potentialSize = 1; // changing this 0 to 1
                    for (auto& kv : neighborComponents) {
                        potentialSize += sizeMap[kv.first];
                    }
                    maxConnected = max(maxConnected, potentialSize);
                }
            }
        }

        for (auto& kv : sizeMap) {
            maxConnected = max(maxConnected, kv.second);
        }

        return maxConnected;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends