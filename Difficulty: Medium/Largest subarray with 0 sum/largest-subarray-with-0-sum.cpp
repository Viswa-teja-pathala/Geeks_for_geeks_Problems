//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        map<int , int> presum;
        int k =0;
        int sum = 0;
        int maxlen = 0;
        for(int i=0; i<n; i++)
        {
            sum +=arr[i];
            if(sum == k)
            {
                maxlen = max(maxlen, i+1);
            }
            int rem = sum - k;
            if(presum.find(rem)!=presum.end())
            {
                int len = i-presum[rem];
                maxlen = max(maxlen, len);
            }
            if(presum.find(sum) == presum.end())
            {
                presum[sum] = i;
            }
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends