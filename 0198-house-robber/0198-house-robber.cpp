class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            int take = nums[i-1];
            int nottake =0 ;
            if(i-2>=0) take+=dp[i-2];
            nottake = dp[i-1]; 
            dp[i] = max(take,nottake);
        }
        return dp[n];
    }
};