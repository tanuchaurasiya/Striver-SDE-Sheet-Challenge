class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,false);
        if(n==1) return true;
        if(nums[0]>0) dp[0]=true;
        for(int i=0;i<n;i++)
        {
            if(dp[i])
            {
                for(int j=1;j<=nums[i];j++){
                    if(i+j<n)
                        dp[i+j]=true;
                    if(i+j==n-1) return true;
                }
            }
        }
        return dp[n-1];
    }
};