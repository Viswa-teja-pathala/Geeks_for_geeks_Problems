//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

class Solution {
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        // Sort jobs by profit in descending order
        sort(arr, arr + n, compare);
        
        // Find the maximum deadline
        int max_dead = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].dead > max_dead) {
                max_dead = arr[i].dead;
            }
        }
        
        // Initialize the slots
        vector<int> slots(max_dead + 1, -1);
        
        // Initialize the result variables
        int count_jobs = 0;
        int total_profit = 0;
        
        // Iterate through the jobs
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (the slot should be before its deadline)
            for (int slot = arr[i].dead; slot > 0; slot--) {
                if (slots[slot] == -1) {
                    slots[slot] = i; // Mark this slot as occupied by job i
                    count_jobs++;
                    total_profit += arr[i].profit;
                    break;
                }
            }
        }
        
        // Return the result as a vector
        return {count_jobs, total_profit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends