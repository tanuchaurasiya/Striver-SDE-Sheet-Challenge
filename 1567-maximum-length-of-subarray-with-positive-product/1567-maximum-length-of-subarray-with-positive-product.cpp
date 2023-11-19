class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int i=0;
        while(i<n){
            int start = i;
            while(start<n && nums[start]==0)
                start++;
            int end = start;
            int startNeg=-1, endNeg = -1;
            int countNeg=0;
            while(end<n && nums[end]!=0){
                if(nums[end]<0){
                    countNeg++;
                    if(startNeg==-1) startNeg=end;
                    endNeg = end;
                }
                end++;
            }
            
            if(countNeg%2==0)
                ans= max(ans, end-start);
            else{
                if(startNeg!=-1) ans=max(ans, end-startNeg-1);
                if(endNeg!=-1) ans=max(ans, endNeg-start);
            }
            i=end+1;
                
        }
        return ans;
    }
};