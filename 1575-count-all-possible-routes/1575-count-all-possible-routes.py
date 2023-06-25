class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        mod=10**9+7    
        @lru_cache(None)
        def fn(n, x): 
            if x < 0:
                return 0
            ans = 0
            if n == finish:
                ans += 1
            for nn in range(len(locations)): 
                if nn != n:
                    ans += fn(nn, x-abs(locations[n] - locations[nn]))
            return ans 
        
        return fn(start, fuel) % mod