//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> res(n, vector<int>(m, -1)); // Initialize res with -1
    vector<int> ans;
    
    int x = 0, y = 0;
    int i = n - 1, j = m - 1;
    
    while (x <= i && y <= j) {
        // Traverse from left to right along the top row
        for (int l = y; l <= j; l++) {
            ans.push_back(mat[x][l]);
            res[x][l] = 1;
        }
        x++;
        
        // Traverse from top to bottom along the right column
        for (int l = x; l <= i; l++) {
            ans.push_back(mat[l][j]);
            res[l][j] = 1;
        }
        j--;
        
        if (x <= i) {
            // Traverse from right to left along the bottom row
            for (int l = j; l >= y; l--) {
                ans.push_back(mat[i][l]);
                res[i][l] = 1;
            }
            i--;
        }
        
        if (y <= j) {
            // Traverse from bottom to top along the left column
            for (int l = i; l >= x; l--) {
                ans.push_back(mat[l][y]);
                res[l][y] = 1;
            }
            y++;
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