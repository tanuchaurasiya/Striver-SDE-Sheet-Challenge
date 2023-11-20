class Solution {
public:
    int help(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i==n-1) return 0;
        if(i>=n) return 100001;
        if(dp[i]!=-1) return dp[i];
        int ans = 100001;
        for(int j=1;j<=nums[i];j++){
            if(i+j<n)
                ans=min(ans, 1+help(i+j,n,nums,dp));
        }
        dp[i]=ans;
        return ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return help(0,n,nums,dp);
    }
};