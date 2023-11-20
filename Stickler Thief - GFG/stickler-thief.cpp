//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int help(int i, int n, int nums[], vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + help(i+2, n, nums, dp);
        int nottake = help(i+1,n,nums, dp);
        dp[i] = max(take, nottake);
        return dp[i];
    }
    
    int FindMaxSum(int nums[], int n)
    {
       vector<int> dp(n,-1);
        return help(0,n,nums,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends