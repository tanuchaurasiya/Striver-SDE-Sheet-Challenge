class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        def help(i,cost,n,dp):
            if i>=n:
                return 0 
            if dp[i]!=-1:
                return dp[i] 
            dp[i]=min(help(i+1,cost,n,dp), help(i+2,cost,n,dp)) + cost[i] 
            return dp[i] 
        dp1=[-1]*1001  
        dp2=[-1]*1001
        n=len(cost)
        return min(help(0,cost,n,dp1), help(1,cost,n,dp2))
            
