//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int help(int idx, int prev, int n, vector<vector<int>> &points, vector<vector<int>> &dp){
        if(idx>=n) return 0;
        if(idx==0){
            int maxx=0;
            for(int i=0;i<3;i++){
                if(i!=prev){
                    maxx=max(maxx, points[idx][i] + help(idx+1, i, n, points, dp));
                }
            }
            return maxx;
        }
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        int maxx=0;
        for(int i=0;i<3;i++){
            if(i!=prev){
                maxx=max(maxx, points[idx][i] + help(idx+1, i, n, points, dp));
            }
        }
       
        dp[idx][prev] = maxx;
        return dp[idx][prev];
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp;
        for(int i=0;i<n;i++)
            dp.push_back({-1,-1,-1});
        
        return help(0, -1, n, points, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends