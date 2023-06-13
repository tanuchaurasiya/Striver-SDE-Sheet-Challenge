#User function Template for python3
#User function Template for python3 
import heapq as hp
class Solution:

    def kLargest(self,arr, n, k): 
        for i in range(n):
            arr[i]=-arr[i]
        hp.heapify(arr) 
        res=[] 
        for i in range(k):
            res.append(-hp.heappop(arr) )
        
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.kLargest(arr, n, k)
        for x in ans:
            print(x, end=" ")
        print()
        tc -= 1

# } Driver Code Ends