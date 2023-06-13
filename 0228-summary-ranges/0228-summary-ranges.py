class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]: 
        i=0
        n=len(nums)
        res=[] 
        while i<n:
            c=nums[i]
            j=i
            i+=1
            flag=0
            while i<n and nums[i]==c+1:
                c=nums[i] 
                i+=1  
                flag=1
            if flag==1 :
                res.append(str(nums[j])+"->"+str(nums[i-1])) 
            else:
                res.append(str(c)) 
            # print(res)
        return res
            