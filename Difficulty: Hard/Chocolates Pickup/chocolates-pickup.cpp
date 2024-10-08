//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
  public:
    int allPaths(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if (j1 < 0 || j1 > m || j2 < 0 || j2 > m)
            return -1e9;
        
        if (i == n) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        // explore all the paths simultaneously
        int mx = INT_MIN;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;
                
                if (j1 == j2)
                    ans = grid[i][j1] + allPaths(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
                else
                    ans = grid[i][j1] + grid[i][j2] + allPaths(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
                
                mx = max(mx, ans);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return allPaths(0, 0, m - 1, n-1, m-1, grid, dp);
    }

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends