//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

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
        
        int j=i;
        while(j<n-1 && candidates[j]==candidates[j+1]){
            j+=1;
        }
        temp.push_back(candidates[i]);
        
        help(j, sum+candidates[i], res,temp, candidates, target, n);
        temp.pop_back();
        help(j+1, sum, res,temp, candidates, target, n);
    }
   vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp; 
        int n = candidates.size(); 
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        help(0, 0, res, temp, candidates, target, n);
        return res;
    }
    
    
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends