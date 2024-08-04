//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
    // Vector to hold the meetings as pairs of (end, start)
    std::vector<std::pair<int, int>> meetings;
    
    for (int i = 0; i < n; ++i) {
        meetings.push_back({end[i], start[i]});
    }

    // Sort the meetings by end time
    std::sort(meetings.begin(), meetings.end());

    int count = 0;
    int last_end_time = -1;

    for (const auto& meeting : meetings) {
        if (meeting.second > last_end_time) {
            count++;
            last_end_time = meeting.first;
        }
    }

    return count;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends