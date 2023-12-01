import heapq 
class Solution: 
    def lexicographicallySmallest (ob, s, k):
        def powerof2(n):
            if n == 1:
                return True
            elif n % 2 != 0 or n == 0:
                return False

            return powerof2(n/2) 
        n=len(s) 
        if powerof2(n):
            k=k//2 
        else:
            k*=2 
        stack=[] 
        i=0 
        removecount=0
       # print(k) 
        if k>=n:
            return -1
        while i<n:
            if not stack:
                stack.append(s[i]) 
                i+=1 
            else:
                if stack[-1]<s[i] :
                    stack.append(s[i]) 
                    i+=1 
                else:
                    while removecount<k and stack and stack[-1]>s[i]:
                        stack.pop(-1) 
                        removecount+=1
                    stack.append(s[i])
                    i+=1 
                          
           # print(stack,i)  
       # print(stack)
        res="" 
        if not stack:
            return "-1"
        for x in range(n-k):
            res+=stack[x] 
       
     
        return res



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        S,k = input().split()
        k=int(k)
        
        ob = Solution()
        print(ob.lexicographicallySmallest(S, k))
# } Driver Code Ends