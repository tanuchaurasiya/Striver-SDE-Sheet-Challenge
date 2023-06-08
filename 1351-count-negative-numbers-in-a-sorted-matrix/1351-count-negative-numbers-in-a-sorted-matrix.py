class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        ctr=0
        for i in range(n):
            for j in range(m-1,-1,-1):
                if grid[i][j]>=0 :
                    break
                else:
                    ctr+=1
        return ctr
        