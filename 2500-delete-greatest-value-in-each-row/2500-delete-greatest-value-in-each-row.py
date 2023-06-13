class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0]) 
        res=0
        for i in range(m): 
            grid[i].sort() 
        print(grid) 
        for j in range(n):
            maxx=-10**9
            for i in range(m):
                maxx=max(maxx,grid[i][j])
            res+=maxx
        return res