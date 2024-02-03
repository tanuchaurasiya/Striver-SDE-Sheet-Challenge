class Solution {
public:
    int solve(vector<int>& arr, int ind, int k, int n,vector<int>& dp)
    {
        if(ind>=n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int max_ele = INT_MIN;
        int sum = 0;
        for(int i=ind; i<min(ind+k,n); i++)
        {
            max_ele = max(max_ele,arr[i]);
            sum = max(sum , solve(arr,i+1,k,n,dp)+(i-ind+1)*max_ele);
        }
        return dp[ind] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(arr,0,k,n,dp);
    }
};