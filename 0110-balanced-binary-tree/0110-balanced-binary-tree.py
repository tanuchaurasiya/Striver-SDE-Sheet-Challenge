# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        if root is None:
            return True
        
        hleft=self.findMaxheight(root.left)
        hright=self.findMaxheight(root.right)
        
        if abs(hleft-hright)>1 or (hleft-hright)<-1:
            return False
        
        if self.isBalanced(root.left) and self.isBalanced(root.right):
            return True
        else:
            return False
          
    def findMaxheight(self,root):
        
        if root is None:
            return 0
        
        return max(self.findMaxheight(root.left)+1,self.findMaxheight(root.right)+1)
        