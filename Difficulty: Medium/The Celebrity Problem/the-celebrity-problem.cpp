//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int l = 0, r = n - 1;
        
        // Step 1: Find the potential celebrity
        while (l < r) {
            if (mat[l][r] == 1) {
                l++;  // l knows r, l cannot be a celebrity
            } else {
                r--;  // l does not know r, r cannot be a celebrity
            }
        }
        
        int candidate = l;
        
        // Step 2: Verify the potential celebrity
        for (int i = 0; i < n; i++) {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
                return -1;  // candidate knows someone or someone does not know the candidate
            }
        }
        
        return candidate;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends