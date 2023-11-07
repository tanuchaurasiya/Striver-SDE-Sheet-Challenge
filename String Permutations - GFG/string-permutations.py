#User function Template for python3

class Solution:
    def permutation(self,S):
        def help(idx,n,temp,res):
            if idx>=n:
                res.append("".join(temp)) 
                
            for i in range(idx,n):
                temp[i],temp[idx]=temp[idx],temp[i] 
                help(idx+1,n,temp,res)
                temp[i],temp[idx]=temp[idx],temp[i] 
        res=[]
        temp=[x for x in S] 
        # print(temp)
        n=len(S)
        help(0,n,temp,res)
        res.sort()
        # print(res)
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    T=int(input())
    while(T>0):
        s=input()
        ob=Solution()
        ans=ob.permutation(s)
        for i in ans:
            print(i,end=" ")
        print()
        
        T-=1
# } Driver Code Ends