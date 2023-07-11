#User function Template for python3

class Solution:
    def findK(self, matrix, n, m, k):
        # Write Your Code here
        c=len(matrix[0])
        r=len(matrix)
        ans=[]
        d=e=i=0
        while(True):
            for j in range(i,c-i):
                e=matrix[i][j]
                ans.append(e)
                d+=1
            if(d>=(r*c)):
                break
            for j in range(i+1,r-i):
                e=matrix[j][c-1-i]
                ans.append(e)
                d+=1
            if(d>=(r*c)):
                break
            for j in reversed(range(i,c-1-i)):
                e=matrix[r-1-i][j]
                ans.append(e)
                d+=1
            if(d>=(r*c)):
                break
            for j in reversed(range(i+1,r-1-i)):
                e=matrix[j][i]
                ans.append(e)
                d+=1
            if(d>=(r*c)):
                break
            i+=1
        return ans[k-1]


#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n, m, k = map(int,input().split())
    a = [
            list(map(int,input().split()))
            for _ in range(n)
        ]
    
    ob = Solution()
    print(ob.findK(a,n,m,k))
    
# } Driver Code Ends