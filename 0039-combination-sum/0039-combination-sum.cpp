class Solution {
public:
    void help(int i, int sum, vector<vector<int>> &res, vector<int> &temp, vector<int>& candidates, int target, int n){
        if(sum>target || i>=n)
            return;
        if(sum==target)
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        help(i, sum+candidates[i], res,temp, candidates, target, n);
        temp.pop_back();
        help(i+1, sum, res,temp, candidates, target, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp; 
        int n = candidates.size(); 
        help(0, 0, res, temp, candidates, target, n);
        return res;
    }
};