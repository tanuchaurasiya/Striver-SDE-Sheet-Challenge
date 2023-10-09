class Solution {
public:
    int left(vector<int> &nums, int tar,int l, int r){
        if(l<=r){
            int m = (l+r)/2; 
            if(nums[m]==tar){
                if(m>0 && nums[m-1]==tar) 
                    return left(nums,tar, l, m-1); 
                return m;
            } 
            else{
                if(nums[m]>tar) 
                    return left(nums,tar,l,m-1); 
                if(nums[m]<tar)
                    return left(nums,tar,m+1,r);
            }
        } 
        return -1;
    } 
    
    
    int right(vector<int> &nums, int tar,int l, int r){
        if(l<=r){
            int m = (l+r)/2; 
            if(nums[m]==tar){
                if(m<nums.size()-1 && nums[m+1]==tar) 
                    return right(nums,tar, m+1, r); 
                return m;
            } 
            else{
                if(nums[m]>tar) 
                    return right(nums,tar,l,m-1); 
                if(nums[m]<tar)
                    return right(nums,tar,m+1,r);
            }
        } 
        return -1;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res;
        res.push_back(left(nums,target,0,nums.size()-1)); 
        res.push_back(right(nums,target,0,nums.size()-1));
        return res;
    }
};