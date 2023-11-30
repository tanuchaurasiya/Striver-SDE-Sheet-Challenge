# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right    
    
class Solution:
    def traverse(self,root):
        if root==None:
            return []
        else:
            return self.traverse(root.left)+[root]+self.traverse(root.right)
   
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        
        arr=self.traverse(root) 
        prev = None
        first = None
        second = None
        for i in range(len(arr)):
            if(prev!=None and prev.val>arr[i].val):
                if(first==None) :
                    first = prev
                second = arr[i]
            prev=arr[i]
        
        first.val,second.val = second.val,first.val 
        
            
        
        
        
        