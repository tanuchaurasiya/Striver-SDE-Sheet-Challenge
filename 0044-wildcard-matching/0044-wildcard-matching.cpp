class Solution {
public:
    bool solve(string &s,string &p,int n,int m,vector<vector<int>> &dp){
        if(n==0 && m==0) return true;
        if(m==0 && n>0) return false;
        if(m>0 && n==0){
            for(int i=1;i<=m;i++){
               if(p[i-1]!='*') return false;
            }
            return true;
        }
        if(dp[n][m]!=-1) return dp[n][m];

        if(p[m-1]==s[n-1] || p[m-1]=='?') return dp[n][m]= solve(s,p,n-1,m-1,dp); 
        else if(p[m-1]=='*') return dp[n][m]=solve(s,p,n-1,m,dp) | solve(s,p,n,m-1,dp);
        return dp[n][m]=0;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n,m,dp);
    }
};