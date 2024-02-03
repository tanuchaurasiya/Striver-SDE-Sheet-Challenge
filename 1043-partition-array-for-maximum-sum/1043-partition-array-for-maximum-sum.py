class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        def helper(i,arr,n,k,dp):
            if(i==n):
                return 0
        
            if(dp[i]!=-1) :
                return dp[i]
        
            maxi=-10**9
            maxians=-10**9
            leng=0
            for j in range(i,min(n,i+k)):
                leng+=1
                maxi=max(maxi,arr[j])
                cost=(maxi*leng) + helper(j+1,arr,n,k,dp)
                maxians=max(maxians,cost) 
        
            dp[i]=maxians 
            return dp[i]
        dp=[-1]*(len(arr))
        return helper(0,arr,len(arr),k,dp)