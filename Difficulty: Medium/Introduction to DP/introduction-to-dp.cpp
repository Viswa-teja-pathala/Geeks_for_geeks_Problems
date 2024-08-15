//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int MOD = 1e9 + 7;
    long long int f(int n, vector<long long int>& dp) {
        if (n <= 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        
        return dp[n] = (f(n-1, dp) + f(n-2, dp))%MOD;
    }

    long long int topDown(int n) {
        vector<long long int> dp(n+1, -1);
        return f(n, dp);
    }

    long long int bottomUp(int n) {
        
        int prev = 0;
        int prev2 = 1;
    

        for (int i = 2; i <= n; i++) {
            int curr = (prev + prev2)%MOD;
            prev = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends