class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        lo, hi = 0, len(arr)-1
        while lo <= hi:
            mid = (lo + hi) // 2
            missing = arr[mid] - (mid+1)
            if missing >= k: 
                hi = mid-1
            else: 
                lo = mid + 1
        return lo + k 
    
# ans = arr[hi] + more = arr[hi] + (k-missing) = arr[hi] + k - (arr[hi] - hi -1) 
#  = arr[hi] + k - arr[hi] + hi + 1 = k + hi + 1 = k + lo  