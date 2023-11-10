//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int mod = 1e9+7;
    public:
    int help(int curr, int n, vector<int> &dp){
	        if(curr==n){
	            return 1; 
	        }
	        
	        if(curr>n) return 0;
	        
	        if(dp[curr]!=-1) return dp[curr];
	        
	        int take = help(curr+1, n,dp);
	        int nottake = help(curr+2, n, dp); 
	        
	        dp[curr] = (take+nottake)%mod; 
	        
	        return dp[curr];
	       
	    }
		int countWays(int n){ 
		    vector<int> dp(n,-1);
		    return help(0, n,dp);
		}
    
    
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends