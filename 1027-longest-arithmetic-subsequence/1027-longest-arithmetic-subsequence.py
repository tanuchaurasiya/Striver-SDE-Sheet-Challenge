class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        d={}
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                diff = nums[j] - nums[i]
                if((i,diff) in d):
                    d[(j, diff)] = d[(i, diff)] +1
                else:
                    d[(j, diff)] = 2
        return max(val for val in d.values())
                    
           