//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int total = n + m;
        int mid1 = (total - 1) / 2; // First middle index for even total
        int mid2 = total / 2;       // Second middle index for even total
        
        int i = 0, j = 0;
        int count = 0;
        int res1 = 0, res2 = 0;
        
        while (i < n && j < m && count <= mid2) {
            if (arr1[i] < arr2[j]) {
                if (count == mid1) res1 = arr1[i];
                if (count == mid2) res2 = arr1[i];
                i++;
            } else {
                if (count == mid1) res1 = arr2[j];
                if (count == mid2) res2 = arr2[j];
                j++;
            }
            count++;
        }
        
        while (i < n && count <= mid2) {
            if (count == mid1) res1 = arr1[i];
            if (count == mid2) res2 = arr1[i];
            i++;
            count++;
        }
        
        while (j < m && count <= mid2) {
            if (count == mid1) res1 = arr2[j];
            if (count == mid2) res2 = arr2[j];
            j++;
            count++;
        }
        
        if (total % 2 == 1) {
            return res2; // Only one middle element
        } else {
            return res1 + res2; // Sum of two middle elements
        }
    }
};


//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends