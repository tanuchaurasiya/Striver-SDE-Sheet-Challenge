class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]: 
        d={}
        l=[]
        n=len(nums)
        for x in nums:
            if x not in d:
                d[x]=1
            else:
                d[x]+=1 
        for x in d:
            if d[x]>(n//3):
                l.append(x)
        # print(l)
        return l
        
        