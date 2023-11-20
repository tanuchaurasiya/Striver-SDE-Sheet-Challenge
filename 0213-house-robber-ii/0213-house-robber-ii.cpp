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
        if(n==1) 
            return nums[0];
        vector<int>nums1,nums2;
        vector<int> dp(n,-1);
         vector<int> dp1(n,-1);
        for(int i=1;i<n;i++)
            nums1.push_back(nums[i]);
        for(int i=0;i<n-1;i++)
            nums2.push_back(nums[i]);
        int n1=nums2.size();
        int ans1 = help(n1-1,nums1,dp);
        int ans2 = help(n1-1, nums2, dp1);
        return max(ans1, ans2);
    }
   
};