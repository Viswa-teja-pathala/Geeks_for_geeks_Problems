//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here
        int count = 0;
    int num = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            if (num < 0 || num > 255) {
                return false;
            }
            count++;
            num = 0;
        } else if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
            if (num > 255) {
                return false;
            }
        } else {
            return false; 
        }
    }

    if (num < 0 || num > 255) {
        return false;
    }
    
    if(count!=3){
        return false;
    }
    return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends