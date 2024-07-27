//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int countMin(string str){
        int n = str.size();
        
        // Create a DP table to store lengths of longest palindromic subsequence
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Strings of length 1 are palindromes of length 1
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        // Build the table. The outer loop is for the length of the substring
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                if(str[i] == str[j] && len == 2)
                    dp[i][j] = 2;
                else if(str[i] == str[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        
        // The minimum number of insertions needed will be
        // the length of the string minus the length of the longest palindromic subsequence
        return n - dp[0][n - 1];
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends