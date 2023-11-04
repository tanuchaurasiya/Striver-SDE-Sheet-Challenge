class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int: 
        def lcs(i1,i2,n1,n2,s1,s2,dp): 
            # print(i1,i2)
            if i1>=n1 or i2>=n2: 
                return 0
            if dp[i1][i2]!=-1:
                return dp[i1][i2]
            m1=-10**9
            m2=-10**9
            if s1[i1]==s2[i2]:
                return lcs(i1+1,i2+1,n1,n2,s1,s2,dp)+1  
            else:       
                m1=lcs(i1+1,i2,n1,n2,s1,s2,dp) 
                m2=lcs(i1,i2+1,n1,n2,s1,s2,dp)  
            # print(m1,m2)
            dp[i1][i2]=max(m1,m2)  
            return dp[i1][i2]
        n1=len(s1)
        n2=len(s2)
        dp=[] 
        for i in range(n1):
            dp.append([-1]*n2)
        return lcs(0,0,n1,n2,s1,s2,dp) 
       