class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefixSum(n), suffixSum(n);
        int prefix=0;
        for (int i = 0; i < n; ++i) {
            prefixSum[i] = prefix;
            prefix+=nums[i];
        }
        int suffix=0;
        for (int i = n-1; i >=0; i--) {
            suffixSum[i] = suffix;
            suffix+=nums[i];
        }
        
        for (int i = 0; i < n; ++i) {
            int currentAbsoluteDiff = ((nums[i] * i) - prefixSum[i]) + (suffixSum[i] - (nums[i] * (n - i - 1)));
            result[i] = currentAbsoluteDiff;
        }
        
        return result;
        
    }
};