class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long l=0;
        long long r=0;
        long long total=0;
        long long res=0;
        sort(nums.begin(), nums.end());
        while(r<nums.size()){
            total+=nums[r];
            while(nums[r]*(r-l+1) > total+k){
                total-=nums[l];
                l+=1;
            }
            res=max(res, r-l+1);
            r+=1;
        }
        return res;
        
    }
};