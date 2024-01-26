class Solution {
public:
    int mod=1e9+7;
    int help(int i, int j, int m, int n, int maxMove, vector<vector<vector<int>>> &dp){
        if(i>=m || j>=n || i<0 || j<0) return 1;
        if(maxMove==0) return 0; 
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
        int x = help(i-1,j,m,n, maxMove-1, dp);
        int y = help(i,j-1,m,n, maxMove-1,dp);
        int z = help(i+1, j, m, n, maxMove-1,dp);
        int p = help(i, j+1, m, n, maxMove-1,dp);
        dp[i][j][maxMove] = (((x+y)%mod+z)%mod+p) % mod; 
        return dp[i][j][maxMove];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m , vector<vector<int>>(n , vector<int>(maxMove + 1 , -1)));
        return help(startRow, startColumn, m,n,maxMove, dp); 
    }
};