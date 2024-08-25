//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        long long count = 0;
    
    // Special cases:
    vector<int> freq(5, 0);  
    for (int y : brr) {
        if (y < 5) {
            freq[y]++;
        }
    }
    
    sort(brr.begin(), brr.end());
    
    for (int x : arr) {
        if (x == 1) continue;  
        
        auto it = upper_bound(brr.begin(), brr.end(), x);
        count += brr.end() - it;
        
        // Handle special cases
        count += freq[1];  // All (x,1) pairs are valid
        if (x == 2) {
            count -= freq[3] + freq[4];  // (2,3) and (2,4) are invalid
        }
        if (x == 3) {
            count += freq[2];  // (3,2) is valid
        }
    }
    
    return count;

    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends