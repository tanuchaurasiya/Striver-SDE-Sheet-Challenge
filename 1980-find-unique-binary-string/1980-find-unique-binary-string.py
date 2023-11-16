class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        
        def help(idx,n,s,nums):
            # print(s,idx)
            if idx>=n: 
                if s in nums:
                    return None
                return s
            x=help(idx+1,n,s+"0",nums)
            if x:
                return x
            x=help(idx+1,n,s+"1",nums)
            if x:
                return x
        return help(0,len(nums[0]),"",nums)
            
            