#User function Template for python3

class Solution:
    def setSetBit(self, x, y, l, r):
        # # code here
        b1=bin(x)[2:]
        b2=bin(y) [2:]
        # print(b2,b1)
        n1=len(b1) 
        n2=len(b2) 
        if n1<32:
            b1="0"*(32-n1) + b1 
        if n2<32:
            b2="0"*(32-n2) + b2  
        # print(b1)
        # print(b2)  
        res=x
        for j in range(l,r+1):
            if b2[32-j] == '1' and b1[32-j]=='0':
                res+=pow(2,j-1) 
        return res
        
        
            
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = input().split()
        x = int(arr[0])
        y = int(arr[1])
        l = int(arr[2])
        r = int(arr[3])
        
        ob = Solution()
        print(ob.setSetBit(x, y, l, r))
# } Driver Code Ends