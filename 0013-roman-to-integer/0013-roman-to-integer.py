class Solution:
    def romanToInt(self, s: str) -> int: 
        d={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000} 
        res=0 
        i=0
        while(i<len(s)):
            c=s[i]  
            x=0 
            while(i<len(s) and s[i]==c): 
                x+=1 
                i+=1   
            
            if(c=='V' and i>1 and s[i-2]=='I'):
                res=res-1+4  
            elif(c=='X' and i>1 and s[i-2]=='I'):
                res=res-1+9 
            elif(c=='L' and i>1 and s[i-2]=='X'):
                res=res-10+40
            elif(c=='C' and i>1 and s[i-2]=='X'):
                res=res-10+90
            elif(c=='D' and i>1 and s[i-2]=='C'):
                res=res-100+400
            elif(c=='M' and i>1 and s[i-2]=='C'):
                res=res-100+900
            else:
                 res=res+d[c]*x  
            # print(res)
        return res
            
                
                
        