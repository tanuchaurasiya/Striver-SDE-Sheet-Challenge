class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
                int diff = nums[j] - nums[i];
                if(dp[i][diff]!=0)
                    dp[j][diff] = dp[i][diff] +1;
                else
                    dp[j][diff] = 2;
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            for(auto j:dp[i])
                res=max(res, j.second);
        }
        return res;
    }
};