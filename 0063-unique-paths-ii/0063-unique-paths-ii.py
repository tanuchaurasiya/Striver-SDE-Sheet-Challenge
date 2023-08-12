class Solution:
    
    def countways(self,row,col,m,n,dp,grid): 
        if row<0 or col<0 or grid[row][col]==1 :
            return 0
        if row==0 and col==0:
            return 1 
        if dp[row][col]!=-1:
            return dp[row][col]
        left=self.countways(row,col-1,m,n,dp,grid) 
        up=self.countways(row-1,col,m,n,dp,grid)
        dp[row][col]=left+up
        return left+up
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int: 
        dp=[]
        a=len(grid)
        b=len(grid[0])
        for i in range(a):
            dp.append([-1]*b)
        return self.countways(a-1,b-1,a,b,dp,grid)
        