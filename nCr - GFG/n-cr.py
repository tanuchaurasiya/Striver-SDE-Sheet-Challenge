#User function Template for python3

import math
class Solution:
    def nCr(self, n, r):
        # code here
        if n<r:
            return 0
        else:
            res=math.factorial(n)//(math.factorial(r)*math.factorial(n-r))
            if res<(10**9):
                return res
            else:
                return res%((10**9)+7)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, r = [int(x) for x in input().split()]
        
        ob = Solution()
        print(ob.nCr(n, r))
# } Driver Code Ends