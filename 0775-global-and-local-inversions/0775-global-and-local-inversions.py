class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        for i, x in enumerate(A):
            if abs(i - x) > 1: return False 
        return True 