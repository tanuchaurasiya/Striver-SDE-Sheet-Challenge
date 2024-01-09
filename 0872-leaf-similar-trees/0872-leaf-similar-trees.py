# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def leaves(root):
            if root:
                if root.left==None and root.right==None:
                    return [root.val]+leaves(root.left)+leaves(root.right)  
                else: 
                    return leaves(root.left)+leaves(root.right)
            return [] 
        l1=leaves(root1)
        l2=leaves(root2) 
        # print(l1,l2)
        if l1!=l2:
            return 0 
        return 1