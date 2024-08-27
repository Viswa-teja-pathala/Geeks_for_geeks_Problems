//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        stack<int> st1, st2;
    vector<int> ls, rs;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        while(!st1.empty() && st1.top() >= arr[i])
            st1.pop();
        if(st1.empty())
            ls.push_back(0);
        else
            ls.push_back(st1.top());
        st1.push(arr[i]);
    }
    for(int i = n-1; i >= 0; i--) {
        while(!st2.empty() && st2.top() >= arr[i])
            st2.pop();
        if(st2.empty())
            rs.push_back(0);
        else
            rs.push_back(st2.top());
            
        st2.push(arr[i]);
    }
    reverse(rs.begin(), rs.end());
    
    
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        ans = max(ans, abs(rs[i]-ls[i]));
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends