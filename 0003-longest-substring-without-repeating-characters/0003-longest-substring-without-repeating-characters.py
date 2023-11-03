class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i=0
        n=len(s) 
        res=0
        while(i<n): 
            st = set(s[i]) 
            j=i+1
            while(j<n):  
                if s[j] not in st: 
                    st.add(s[j]) 
                    j+=1 
                else: 
                    res=max(res, j-i) 
                    break 
            
            res=max(res, j-i) 
            i+=1;
            
        return res
                    
                    
                
                
        