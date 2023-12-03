//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int dp[1000][1000];
    vector<vector<int>> moves{{-1,0}, {1, 0}, {0,-1}, {0,1}};
    
    bool isvalid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    
    int help(int i, int j, int m ,int n,vector<vector<int>>& matrix){
        int ans=1;
        if(dp[i][j]) return dp[i][j];
        for(auto adj:moves){
            if(isvalid(i+adj[0], j+adj[1], m, n) && matrix[i][j]<matrix[i+adj[0]][j+adj[1]]){
                ans=max(ans, 1+help(i+adj[0], j+adj[1], m, n, matrix));
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int m, int n) {
        memset(dp,0, sizeof(dp));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ 
                if(!dp[i][j])
                    res=max(res, help(i, j, m, n, matrix));
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends