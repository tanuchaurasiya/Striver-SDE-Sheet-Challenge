class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead. 
        
        """  
        lnew=nums1[:len(nums1)-len(nums2)] 
        i=0 
        j=0  
        l=[]
        while(i<len(lnew) and j<len(nums2)): 
            if(lnew[i]<nums2[j]):
                l.append(lnew[i])  
                # print(l)
                i+=1 
                  
            elif(lnew[i]>nums2[j]): 
                l.append(nums2[j]) 
                # print(l)
                j+=1 
            else:
                l.append(lnew[i])
                l.append(lnew[i]) 
                # print(l)
                i+=1 
                j+=1 
        
        while(i<len(lnew)):
            l.append(lnew[i]) 
            i+=1 
        while(j<len(nums2)): 
            l.append(nums2[j])  
            j+=1  
        # print(l)
        for k in range(len(l)): 
            nums1[k]=l[k] 
        return len(l)
        