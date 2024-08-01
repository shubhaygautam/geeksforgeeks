//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n = mat.size()-1, m = mat[0].size()-1;
        int total = (n+1)*(m+1);
        
        vector<int> v;
        int s1=0, s2=0;
        
        while(v.size()<total)
        {
            for(; s2<=m; s2++)
            {
                if(mat[s1][s2] == -1) break;
                
                v.push_back(mat[s1][s2]);
                mat[s1][s2] =  -1;
            }
            s2--;
            s1++;
            for(; s1<=n; s1++)
            {
                if(mat[s1][s2] == -1) break;
                
                v.push_back(mat[s1][s2]);
                mat[s1][s2] =  -1;
            }
            s1--;
            s2--;
            for(; s2>=0; s2--)
            {
                if(mat[s1][s2] == -1) break;
                
                v.push_back(mat[s1][s2]);
                mat[s1][s2] =  -1;
            }
            s2++;
            s1--;
            for(; s1>=0; s1--)
            {
                if(mat[s1][s2] == -1) break;
                
                v.push_back(mat[s1][s2]);
                mat[s1][s2] =  -1;
            }
            s1++;
            s2++;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends