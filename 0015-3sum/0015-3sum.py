class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]: 
        n=len(nums) 
        nums.sort() 
        # print(nums)
        res=[]
        i=0
        while i<n:
            j=i+1 
            k=n-1 
            while j<n and k>j:
                # print(i,j,k)
                if nums[i] + nums[j] + nums[k] ==0:
                    if [nums[i],nums[j],nums[k]] not in res:
                        res.append([nums[i],nums[j],nums[k]]) 
                    j+=1
                    k-=1 
                elif nums[i] + nums[j] + nums[k] <0:
                    j+=1 
                else:
                    k-=1 
            i+=1 
        return res

        

