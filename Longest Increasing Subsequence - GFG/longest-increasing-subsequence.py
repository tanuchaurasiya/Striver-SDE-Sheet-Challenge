#User function Template for python3

from bisect import bisect_left

class Solution:
    def longestSubsequence(self,nums,n):
        arr = []
        
        for num in nums:
            insertion_pos = bisect_left(arr, num)
            
            if insertion_pos == len(arr):
                arr.append(num)
            else:
                arr[insertion_pos] = num
        
        return len(arr)






#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        a = [ int(x) for x in input().split() ]
        ob=Solution()
        print(ob.longestSubsequence(a,n))
# } Driver Code Ends