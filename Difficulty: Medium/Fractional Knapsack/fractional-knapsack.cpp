//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
    static bool cmp(Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, cmp);
        double result = 0;
        int wei = w;

        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= wei) {
                result += arr[i].value;
                wei -= arr[i].weight;
            } else {
                result += arr[i].value * ((double)wei / arr[i].weight);
                break;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends