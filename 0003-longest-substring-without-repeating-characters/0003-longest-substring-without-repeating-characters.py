class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        final=""
        res=0
        x=0
        if(len(s)==1):
            return 1
        while(x<len(s)):
            if s[x] not in final:
                final+=s[x]
                x+=1
                continue 
            else:
                if res<len(final):
                    res=len(final) 
                # print(final)
                idx=final.index(s[x])
                if(idx<len(final)-1):
                    final=final[idx+1:] 
                else:
                    final=""
        # print(final)
        if(len(final)>res):
            res=len(final)
            
        return res
        