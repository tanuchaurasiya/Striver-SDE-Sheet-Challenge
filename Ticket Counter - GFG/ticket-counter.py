class Solution:
    def distributeTicket(self, N : int, K : int) -> int:
        # Code Here
        start , end = 1,N
        dup = K
        while start < end:
            while dup != 0 and start < end:
                start += 1
                dup -= 1
            if start == end:
                return start
            dup = K
            while dup != 0 and start< end:
                end -= 1
                dup -= 1
            if start == end:
                return start
            dup = K
        return start


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    
    N, K = map(int, input().split())
    
    obj = Solution()
    res = obj.distributeTicket(N, K)
    
    print(res)
# } Driver Code Ends