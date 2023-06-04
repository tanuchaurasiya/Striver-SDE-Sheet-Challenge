#User function Template for python3
class Solution:
    def reverseEqn(self, s):
        # code here
        stack=[]
        cur=""
        for i in s:
            if i.isnumeric():
                cur+=i
            else:
                stack.append(cur)
                stack.append(i)
                cur=""
        stack.append(cur)
        stack=stack[::-1]
        return "".join(stack)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        ans = ob.reverseEqn(s)
        print(ans)
# } Driver Code Ends