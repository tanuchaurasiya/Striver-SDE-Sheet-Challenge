from collections import Counter
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        row=Counter() 
        col=Counter() 
        n=len(grid)
        for i in range(n):
            row[tuple(grid[i])]+=1
            temp=tuple()
            for j in range(n):
                temp+=(grid[j][i],) 
            col[temp]+=1 
        print(row,col) 
        res=0
        for key,val in row.items():
            if col[key]>0:
                res+=row[key]*col[key]
        return res