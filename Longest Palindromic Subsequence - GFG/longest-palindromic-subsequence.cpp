//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int help(string A, string revA, int n, int i, int j, vector<vector<int>> &dp)
    { 
        if(i>=n or j>=n) 
            return 0; 
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if (A[i]==revA[j]) 
            return 1+help(A,revA,n,i+1,j+1,dp); 
        dp[i][j] = max(help(A,revA,n,i+1,j,dp), help(A,revA,n,i,j+1,dp));
        return dp[i][j];
           
    }
    int longestPalinSubseq(string A) {
        string revA; 
        int n=A.length(); 
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int i=0;i<n;i++) 
            revA+=A[n-i-1]; 
        return help(A,revA,n,0,0,dp); 
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends