#User function Template for python3
from queue import Queue 
from queue import LifoQueue
class Solution:
    #Function to reverse the queue.
    def rev(self, q):
        res= Queue() 
        stack = [] 
        while not q.empty(): 
            x=q.get()
            stack.append(x) 
        while stack:
            res.put(stack.pop())
        return res


#{ 
 # Driver Code Starts

#Initial Template for Python 3

from queue import Queue
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        n=int(input())
        a=list(map(int,input().split()))
        q=Queue(maxsize=n)
        for j in a:
            q.put(j)
            
        ob = Solution()
        q=ob.rev(q)
        for i in range(0,n):
            print(q.get(),end=" ")
        print()
# } Driver Code Ends