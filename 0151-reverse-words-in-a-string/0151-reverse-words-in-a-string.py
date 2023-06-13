class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.strip() 
        n=len(s) 
        # print(s)
        i=n-1
        j=0 
        while i>=j:
            word=""
            previ=i 
            prevj=j
            while i>-1 and s[i]!=" ":
                word=s[i]+word 
                i-=1 
            i-=1 
            word1="" 
            while j<n and s[j]!=" ":
                word1+=s[j] 
                j+=1 
            j+=1 
            if word==word1:
                continue
            s=s[:prevj]+word+" "+s[j:i+2]+word1+s[previ+1:]
            diff=abs(len(word)-len(word1))
            if diff>0:
                if len(word)>len(word1):
                    i+=diff
                    j+=diff
                else:
                    i-=diff
                    j-=diff
            # print(s,i,j,len(s))
        
        i=0
        print(s)
        while i<n:
            count=0
            tempi=i 
            while i<n and s[i]==" ":
                # print("s",s,i,n)
                count+=1 
                i+=1 
            # print(i,count)
            if count>1:
                s=s[:tempi]+ " "+s[i:] 
                i-=(count)
                n=n-count+1
            i+=1 
            # print(i,s)
        return s
            