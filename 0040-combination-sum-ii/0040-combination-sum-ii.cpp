


class Solution {
  public:
    void help(int i, int sum, vector<vector<int>> &res, vector<int> &temp, vector<int>& candidates, int target, int n){
        if(sum==target)
        {
            res.push_back(temp);
            return;
        }
        if(sum>target || i>=n)
            return;
        
        // cout<<i<<" "<<sum<<endl;
        temp.push_back(candidates[i]);
    
        help(i+1, sum+candidates[i], res,temp, candidates, target, n);
        temp.pop_back(); 
        
        while(i+1 < n && candidates[i] == candidates[i+1]) i++;
        help(i+1, sum, res,temp, candidates, target, n);
    }
   vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<vector<int>> res;
        vector<int> temp; 
        int n = candidates.size(); 
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        help(0, 0, res, temp, candidates, target, n);
        return res;
    }
    
};