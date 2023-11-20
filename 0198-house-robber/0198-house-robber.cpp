class Solution {
public:
    int help(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + help(i+2, n, nums, dp);
        int nottake = help(i+1,n,nums, dp);
        dp[i] = max(take, nottake);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return help(0,n,nums,dp);
    }
};