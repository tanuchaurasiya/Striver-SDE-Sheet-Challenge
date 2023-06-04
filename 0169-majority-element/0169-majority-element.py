from collections import *
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d=defaultdict(int)
        n=len(nums)
        n1=n//2
        for x in nums:
            d[x]+=1 
            if d[x]>n1:return x 
	