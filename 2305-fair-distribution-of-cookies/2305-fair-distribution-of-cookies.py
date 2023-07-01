class Solution:
	def distributeCookies(self, cookies: List[int], k: int) -> int:
		self.ans = inf
		self.length = len(cookies)
		cookies.sort(reverse = True)
		self.helper([0]*k,cookies,0,0,k)
		return self.ans

	def helper(self, child, cookies, ind,c,k):
		if ind < self.length:
			for j in range(k):
				if child[j] + cookies[ind] < self.ans:
					child[j] += cookies[ind]
					self.helper(child,cookies,ind+1,j,k)
					child[j] -= cookies[ind]  
			return 
		self.ans = min(self.ans,max(child))