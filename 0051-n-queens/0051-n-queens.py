class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def isSafe(row,col,board,n,bottomDia,upperDia,horizontalRow):
            if bottomDia[row+col]==1 or upperDia[n-1+col-row]==1 or horizontalRow[row]==1:
                return 0 
            return 1
        
        def solve(col,board,ans,n,bottomDia,upperDia,horizontalRow):
            if col==n:
                temp=[]
                for i in range(n):
                    s="".join(board[i]) 
                    temp.append(s)
                ans.append(temp)
                return 
            for row in range(n):
                if isSafe(row,col,board,n,bottomDia,upperDia,horizontalRow):
                    board[row][col]='Q'  
                    bottomDia[row+col]=1 
                    upperDia[n-1+col-row]=1 
                    horizontalRow[row]=1 
                    solve(col+1,board,ans,n,bottomDia,upperDia,horizontalRow)
                    board[row][col]='.'
                    bottomDia[row+col]=0
                    upperDia[n-1+col-row]=0 
                    horizontalRow[row]=0
        ans=[]
        board=[] 
        N=2*n-1
        bottomDia=[0]*N
        upperDia=[0]*N
        horizontalRow=[0]*N 
        for i in range(n):
            s=["."]*n
            board.append(s) 
        solve(0,board,ans,n,bottomDia,upperDia,horizontalRow)
        return ans 
        