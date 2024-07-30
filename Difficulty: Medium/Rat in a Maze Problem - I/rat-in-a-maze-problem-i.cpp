//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void func(int i, int j, int n, int m, string str, vector<string>& ans, vector<vector<int>>& mat, vector<vector<int>>& visited) {
    if (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1 && !visited[i][j]) {
        if (i == n - 1 && j == m - 1) {
            ans.push_back(str);
            return;
        }

        // Mark the cell as visited
        visited[i][j] = 1;

        // Explore all four possible directions
        func(i + 1, j, n, m, str + 'D', ans, mat, visited);
        func(i, j + 1, n, m, str + 'R', ans, mat, visited);
        func(i - 1, j, n, m, str + 'U', ans, mat, visited);
        func(i, j - 1, n, m, str + 'L', ans, mat, visited);

        // Unmark the cell as visited (backtracking)
        visited[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    int n = mat.size();
    int m = mat[0].size();

    // Create a visited matrix to keep track of visited cells
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Check if the starting cell is blocked
    if (mat[0][0] == 0 || mat[n-1][m-1] == 0) {
        return ans;  // Return empty list if the start or end is blocked
    }

    // Start DFS from the top-left corner (0, 0)
    func(0, 0, n, m, "", ans, mat, visited);

    return ans.empty() ? vector<string>{ "-1" } : ans;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends