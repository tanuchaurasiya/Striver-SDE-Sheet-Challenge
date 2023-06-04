class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        summ=sum(nums) 
        summ1=n*(n+1)//2 
        return summ1-summ