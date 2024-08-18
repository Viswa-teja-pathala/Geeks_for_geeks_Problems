//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        long long int sum1 = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            sum1 += arr[i];
        }
        
        if(sum1%2 == 1){
            return false;
        }
        
        long long int sum2 = sum1/2;
        long long int sum3 = 0;
        
        for(int i=0; i<n; i++){
            if(sum3 == sum2){
                return true;
            }
            
            sum3 += arr[i];
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends