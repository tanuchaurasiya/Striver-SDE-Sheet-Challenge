class Solution {
public:
    bool help(int i, int j, string s, string p, int n, int m, vector<vector<int>>&dp){
        if(i>=n && j>=m) 
            return true;
        if(i>=n && j<m){
            while(j<m ){
                if(p[j]!='*') return false;
                j++;
            }
            return true;
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
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return help(0,0,s,p,n,m, dp);
    }
};