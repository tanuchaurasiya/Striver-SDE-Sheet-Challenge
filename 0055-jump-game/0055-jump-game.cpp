class Solution {
public:
    bool help(int i, vector<int> &nums, int n, vector<int>&dp){
        if(i==n-1) 
            return true;
        if(i>=n) 
            return false;
        if(dp[i]!=-1){ 
            if(dp[i]==1) 
                return true;   
            return false;
        }
        
        for(int j=1;j<=nums[i];j++){
            if (help(i+j, nums, n,dp)){
                dp[i]=1;
                return true;
            }
        }
        dp[i]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return help(0, nums,n,dp);
    }
};