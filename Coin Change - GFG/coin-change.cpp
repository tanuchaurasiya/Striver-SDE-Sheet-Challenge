//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  
public:
    long long int dp[1001][1001]; 
    int n;
    long long int helper(int indx, int target, int* coins){
        if (target == 0)
        return 1;
        
        if (indx == n)
        return 0;
        
        if (dp[indx][target] != -1)
        return dp[indx][target];
        
        long long int take = 0, skip = 0;
        if (target >= coins[indx])
        take = helper(indx,target - coins[indx],coins);
        skip = helper(indx+1, target, coins);

        return dp[indx][target] = take + skip;
    }

long long int count(int coins[], int N, int sum) {
    memset(dp,-1,sizeof(dp));
        n = N;
        return helper(0,sum,coins);
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends