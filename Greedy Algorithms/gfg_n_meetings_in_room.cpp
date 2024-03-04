//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    bool compareRows(const std::vector<int>& row1, const std::vector<int>& row2, int column) {
            return row1[column] < row2[column];
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {   
        vector<vector<int>> data_store;
        // Your code here
        for (int i=0; i < n; i++){
            vector<int> temp;
            temp.push_back(start[i]);
            temp.push_back(end[i]);
            data_store.push_back(temp);
        }
        
        std::sort(data_store.begin(), data_store.end(), [&](const std::vector<int>& row1, const std::vector<int>& row2) {
            return compareRows(row1, row2, 1);
        });
        
        
        int last_ended = 0;
        int max_meetings = 0;
        
        for (int i = 0; i< data_store.size(); i++){
            vector<int> currentRow = data_store[i];
            if (currentRow[0] > last_ended){
                last_ended = currentRow[1];
                max_meetings += 1;
            }
        }
        
        return max_meetings;
    
        
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
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends