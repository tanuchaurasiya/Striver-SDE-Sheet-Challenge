class Solution:
    def findDuplicate(self, nums: List[int]) -> int: 
        var1=0
        while 1:
            if nums[var1]==0:
                return var1
            
            temp=nums[var1] 
            nums[var1]=0  
            var1=temp 
            