class Solution {
public:
    void swap(int i, int j, vector<int> &nums){
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void help(int idx, int n , vector<int> &nums, vector<vector<int>> &res){
        if(idx>=n)
            res.push_back(nums);
        for(int i=idx; i<n; i++){
            swap(i, idx, nums); 
            help(idx+1, n, nums, res);
            swap(i, idx, nums); 
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>> res; 
     int n = nums.size();
     help(0,n,nums,res); 
     return res;
    }
};