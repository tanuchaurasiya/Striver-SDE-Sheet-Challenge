#User function Template for python3
#User function Template for python3

 
class Solution:
    def isSubsetSum (self, n,nums,k):
        def help(i,summ):
            nonlocal nums,k,n,dp 
            # print(summ)
            if summ==k:
                return 1
            if i>=n or summ>k:
                return 0
            if dp[i][summ]!=-1:
                return dp[i][summ]
            take=help(i+1,summ+nums[i])
            nottake=help(i+1,summ)
            dp[i][summ]=take or nottake
            return dp[i][summ]
        
        dp=[]
        for i in range(n):
            dp.append([-1]*(k+1))
        
        return help(0, 0)
    
        

        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        arr = input().split()
        for itr in range(N):
            arr[itr] = int(arr[itr])
        sum = int(input())

        ob = Solution()
        if ob.isSubsetSum(N,arr,sum)==True:
            print(1)
        else :
            print(0)
            
        

# } Driver Code Ends