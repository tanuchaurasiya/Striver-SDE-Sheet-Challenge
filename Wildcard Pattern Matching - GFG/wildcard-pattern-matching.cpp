//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    bool help(int i, int j, string s, string p, int n, int m, vector<vector<int>>&dp){
        if(i>=n && j>=m) 
            return true;
        if(i>=n && j<m){
            while(j<m && p[j]=='*')
                j++;
            if(j==m)
                return true;
            return false;
        }
            
        if(i<n && j>=m)
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='?') 
            dp[i][j] = help(i+1, j+1, s, p, n,m,dp);
        else if(p[j]=='*')
            dp[i][j] = help(i,j+1,s,p,n,m,dp) || help(i+1, j,s,p,n,m,dp);
        
        else
            dp[i][j]=false;
        return dp[i][j];
            
    }
    
    int wildCard(string p,string s)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp;
        for(int i=0;i<n+1;i++)
        {
            vector<int> v;
            for(int j=0;j<m+1;j++)
                v.push_back(-1);
            dp.push_back(v);
        }
        return help(0,0,s,p,n,m, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends