class Solution {
public:
    int dp[200][200];
    vector<vector<int>> moves{{-1,0}, {1, 0}, {0,-1}, {0,1}};
    
    bool isvalid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    
    int help(int i, int j, int m ,int n,vector<vector<int>>& matrix){
        int ans=1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(auto adj:moves){
            if(isvalid(i+adj[0], j+adj[1], m, n) && matrix[i][j]<matrix[i+adj[0]][j+adj[1]]){
                ans=max(ans, 1+help(i+adj[0], j+adj[1], m, n, matrix));
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp,-1, sizeof(dp));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ 
                res=max(res, help(i, j, m, n, matrix));
            }
        }
        return res;
    }
};