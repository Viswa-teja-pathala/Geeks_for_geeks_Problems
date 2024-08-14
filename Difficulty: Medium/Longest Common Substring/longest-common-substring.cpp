//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n = str1.size();
        int m = str2.size();
        int maxi = 0;
        
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(str1[i] == str2[j]){
                    count = 1;
                    int x = i+1;
                    int y = j+1;
                    if(maxi > n-i){
                        return maxi;
                    }
                    while(str1[x]==str2[y] && x<n && y<m){
                        count++;
                        
                        x++;
                        y++;
                    }
                    
                    maxi = max(maxi, count);
                }
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends