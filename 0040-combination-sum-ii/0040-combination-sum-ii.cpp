class Solution {
public: 
    void help(int i,vector<int> &candidates,int target,int sum,vector<int> &subset,vector<vector<int>> &ans){
       //Base conditions
       if(sum == target){
           ans.push_back(subset);
           return;
       }
       if(sum > target) return;
       if(i >= candidates.size()) return;
       
       //Including ith element
       subset.push_back(candidates[i]);
       sum += candidates[i];
       help(i+1,candidates,target,sum,subset,ans);
	   cout<<"1 "<<sum<<endl;
	   //Backtracking Step
       subset.pop_back();
       sum -= candidates[i];
       cout<<sum<<endl;
       //Skip ith element
       while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
       help(i+1,candidates,target,sum,subset,ans);
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        help(0,candidates,target,sum,subset,ans);
        return ans;
    }
};