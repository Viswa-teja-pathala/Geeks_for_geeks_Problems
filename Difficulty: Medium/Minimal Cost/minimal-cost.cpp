//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int func(vector<int>& arr, int ind, int k, vector<int>& dp) {
        if(ind == 0) {
            return 0;
        }
        
        if(dp[ind] != -1) {
            return dp[ind];
        }
        
        int minsteps = INT_MAX;  
        
        for(int i = 1; i <= k; i++) {
            if(ind - i >= 0) {
                int jump = func(arr, ind - i, k, dp) + abs(arr[ind] - arr[ind - i]);
                minsteps = min(minsteps, jump);
            }
        }
        
        return dp[ind] = minsteps;
    }
    
    int minimizeCost(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);  
        return func(arr, n - 1, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends