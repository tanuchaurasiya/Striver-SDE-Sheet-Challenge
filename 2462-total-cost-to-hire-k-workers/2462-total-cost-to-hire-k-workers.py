import heapq
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n=len(costs)
        i=0
        j=n-1 
        h=[] 
        while i<candidates:
            h.append([costs[i],i]) 
            i+=1 
        while j>=max(i,n-candidates):
            h.append([costs[j],j])
            j-=1 
        # print(h)
        heapq.heapify(h) 
        print(h,i,j)
        res=0
        while i<=j and k>0:
            val,idx=heapq.heappop(h)
            res+=val 
            if idx<i:
                heapq.heappush(h,[costs[i],i]) 
                i+=1 
            elif idx>i:
                heapq.heappush(h,[costs[j],j]) 
                j-=1 
            k-=1 
        while k>0:
            val,idx=heapq.heappop(h)
            res+=val
            k-=1
        return res
            