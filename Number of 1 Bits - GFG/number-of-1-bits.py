#User function Template for python3
class Solution:
	def setBits(self, N):
	    numberOf1s=0
        while(N>0):
            if(N%2==1):
                numberOf1s+=1
            N=N//2
        return numberOf1s


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		ob = Solution()
		ans = ob.setBits(N)
		print(ans)




# } Driver Code Ends