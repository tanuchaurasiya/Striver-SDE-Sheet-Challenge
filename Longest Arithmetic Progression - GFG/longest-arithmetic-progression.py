#User function Template for python3

class Solution:
    def lengthOfLongestAP(self, nums, n):
        # code here
        d={}
        if n<=2:
            return n
        for i in range(n):
            for j in range(i+1, n):
                diff = nums[j] - nums[i]
                if((i,diff) in d):
                    d[(j, diff)] = d[(i, diff)] +1
                else:
                    d[(j, diff)] = 2
        return max(val for val in d.values())


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        A = list(map(int, input().split()))
        ob = Solution()
        ans = ob.lengthOfLongestAP(A, n)
        print(ans)
        tc -= 1

# } Driver Code Ends