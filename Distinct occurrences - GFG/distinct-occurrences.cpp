//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      int m = s.size() , n = t.size();
      int mod = 1e9+7;
        vector<vector<int>> dp( m+1 , vector<int>(n+1,0) );
        for(int i=0;i<=m;i++) dp[i][0] = 1;
        for(int j=1;j<=n;j++) dp[0][j] = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                }
                else{
                    dp[i][j] = dp[i-1][j] % mod;
                } 
          }
        }
        return dp[m][n] % mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends