class Solution {
public:
    int help(int i,vector<int> &nums, vector<int> &dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + help(i-2, nums, dp);
        int nottake = help(i-1,nums, dp);
        dp[i] = max(take, nottake);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return help(n-1,nums,dp);
    }
};