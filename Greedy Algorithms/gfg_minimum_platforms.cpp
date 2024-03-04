//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    static bool customCompare(const pair<int, bool>& a, const pair<int, bool>& b) {
    if (a.first != b.first) { // If integers are different, sort based on integers
        return a.first < b.first;
    }
    // If integers are same, sort based on boolean value
    return a.second > b.second; // 'true' comes before 'false'
}
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int numPlatforms = 1;
    	int currentTrains = 0;
    	
    	vector<pair<int, bool>> trainSchedule;
    	
    	for (int i=0; i<n; i++){
    	    trainSchedule.push_back(make_pair(arr[i], true));
    	    trainSchedule.push_back(make_pair(dep[i], false));
    	}
    	
	    sort(trainSchedule.begin(), trainSchedule.end(), customCompare);
    	
    	for (const auto& pair: trainSchedule){
    	    if (pair.second == true){
    	        currentTrains += 1;
    	    }else{
    	        currentTrains -= 1;
    	    }
    	    if (currentTrains > numPlatforms){
    	        numPlatforms = currentTrains;
    	    }
    	}
    	
    	return numPlatforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends