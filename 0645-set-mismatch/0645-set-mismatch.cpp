class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int rep;
        int mis;
        int n = nums.size();
        int sum=0;
        int expected_sum = n*(n+1)/2; 
        for(int i=0;i<n;i++){
            int j = abs(nums[i]); 
            if(nums[j-1]<0) {
                rep=j;
            }
            nums[j-1] = -nums[j-1];
            sum+=abs(nums[i]);
        } 
        sum-=rep;
        return {rep, expected_sum-sum};
    } 
};