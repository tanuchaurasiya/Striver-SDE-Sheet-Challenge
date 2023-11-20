//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int FindMaxSum(int nums[], int n)
    {

        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int take = nums[i-1];
            int nottake =0 ;
            if(i-2>=0) take+=dp[i-2];
            nottake = dp[i-1]; 
            dp[i] = max(take,nottake);
        }
        return dp[n];
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