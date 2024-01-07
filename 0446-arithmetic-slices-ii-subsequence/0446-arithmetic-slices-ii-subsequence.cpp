class Solution {
public:
    void help(vector<int> &nums, int &ans){
        int n = nums.size();
        vector<unordered_map<long,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=0; j<i;j++){
                long diff = (long)nums[i] - nums[j];
                if(dp[j][diff] !=0){
                    ans+=dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                dp[i][diff] +=1; 
                
            }
        }
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        help(nums, ans);
        return ans;
    }
};