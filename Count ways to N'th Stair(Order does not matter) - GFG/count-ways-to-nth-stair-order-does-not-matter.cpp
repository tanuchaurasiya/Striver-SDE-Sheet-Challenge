//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int help(int curr,int i, int n, vector<int> v, vector<vector<int>> &dp){
	       // cout<<curr<<endl;
	        if(curr==n)
	            return 1; 
	        if(curr>n || i>1) return 0;
	        
	        if(dp[i][curr]!=-1) return dp[i][curr];
	        
	        int take = help(curr+v[i], i, n,v,dp);
	        int nottake = help(curr, i+1, n,v,dp);
	        
	       // cout<<take<<" "<<nottake<<endl;
	        dp[i][curr]=take+nottake; 
	        return dp[i][curr];
	    }
		int nthStair(int n){
		    //  Code here
		    vector<vector<int>> dp;
		    for(int i=0;i<2;i++){
		        vector<int> v;
		        for(int i=0;i<n+1;i++)
		            v.push_back(-1);
		        dp.push_back(v);
		    }
		    return help(0, 0, n,{1,2},dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends