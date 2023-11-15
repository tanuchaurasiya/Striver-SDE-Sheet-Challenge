class Solution { 
public:
    int help(int i, int j, string s, string t, int n1, int n2, vector<vector<int>> &dp){
        if(j==n2+1) {
            return 1;
        }
        if(i==n1+1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int x =0;
        int y =0;
        if(s[i-1]==t[j-1]) 
            x = help(i+1, j+1, s, t, n1, n2, dp); 
        y =  help(i+1, j, s, t, n1, n2,dp);
        dp[i][j] = x+y;
        return dp[i][j];
    }
    int numDistinct(string s, string t) { 
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,-1));  
        
        
        int r = help(1,1,s,t, n1, n2, dp);
        return r;
    }
};