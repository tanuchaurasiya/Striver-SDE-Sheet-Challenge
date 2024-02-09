class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n < 2:
            return nums

        nums.sort()
        LDS = [[num] for num in nums]

        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0 and ( len(LDS[j]) + 1 > len(LDS[i]) ):
                    LDS[i] = LDS[j] + [nums[i]]
        
        return max(LDS, key=len)


        