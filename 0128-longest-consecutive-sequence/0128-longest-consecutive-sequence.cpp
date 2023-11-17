// Watch striver vdo
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        if(n==0)return 0;
        sort(nums.begin(), nums.end());
        int i=1;
        int count=1;
        long long int prev = nums[0];
        while(i<n){
            if(nums[i]==prev) 
                i++;
            
            else if(nums[i]==prev+1) {
                prev=nums[i];
                i++;
                count++;
            } 
            
            else
            {
                res=max(res, count);
                prev=nums[i];
                count=1;
                i++;
            }
            
        }
        res=max(res, count);
        return res;
    }
};