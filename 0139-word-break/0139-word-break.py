class Solution:
    def wordBreak(self, s: str, word: List[str]) -> bool:
        def help(i,n,s,temp,words,d):
            # print(temp)
            if i>=n:
                if temp=="" or temp in words:
                    return 1
                return 0  
            if temp in dp[i]:
                return dp[i][temp]
            x=0
            y=0
            if temp in words:
                x=help(i,n,s,"",words,dp)
                
            y=help(i+1,n,s,temp+s[i],words,dp)
                
            dp[i][temp]=x or y
            return dp[i][temp]
        n=len(s)
        dp=[] 
        for i in range(n):
            d1=dict() 
            dp.append(d1)
        res=help(0,n,s,"",word,dp)
        return res
            
        