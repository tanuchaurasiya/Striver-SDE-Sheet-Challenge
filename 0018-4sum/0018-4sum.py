class Solution:
    def fourSum(self, arr: List[int], tar: int) -> List[List[int]]:
        n=len(arr)
        i=0
        res=set()
        arr.sort()
        while i<n:
            j=i+1
            while j<n:
                k=j+1
                l=n-1
                while k<n and l>k:
                    if arr[i]+arr[j]+arr[k]+arr[l]==tar:
                        # print([arr[i],arr[j],arr[k],arr[l]])
                        res.add((arr[i],arr[j],arr[k],arr[l]))
                        k+=1
                        l-=1
                    elif arr[i]+arr[j]+arr[k]+arr[l]<tar:
                        k+=1
                    elif arr[i]+arr[j]+arr[k]+arr[l]>tar:
                        l-=1 
                j+=1                
            i+=1 
        return list(res)