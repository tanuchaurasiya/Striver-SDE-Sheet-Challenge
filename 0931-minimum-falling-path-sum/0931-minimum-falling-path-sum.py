class Solution: 
    def help(self,dp,mat,n,m):
        for j in range(m):
            dp[0][j]=mat[0][j] 
#         print(dp)
        for i in range(1,n):
            for j in range(m):
                downleft=1000000009 
                downright=1000000009 
                down=dp[i-1][j] + mat[i][j]
                if j-1>=0:
                    downleft=dp[i-1][j-1] + mat[i][j]
                if j+1<m:
                    downright=dp[i-1][j+1] + mat[i][j]
                dp[i][j]=min(down,downleft,downright) 
#         print(dp)
        return min(dp[n-1])
    def getMaxPathSum(self,matrix):
        l=[] 
        n=len(matrix) 
        m=n
        dp=[]
        for i in range(n):
            dp.append([-1]*m)
        for j in range(m):
            l.append(self.help(dp,matrix,m,n)) 
            # print(l)
        return min(l)
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        return self.getMaxPathSum(matrix)
        