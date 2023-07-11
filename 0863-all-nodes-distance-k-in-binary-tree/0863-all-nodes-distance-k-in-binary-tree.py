# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        def findparent(root):
            if root==None:
                return 
            if root.left:
                parent[root.left] = root
            if root.right:
                parent[root.right] = root
            findparent(root.left) 
            findparent(root.right) 
        parent={} 
        parent[root] = None
        findparent(root) 
        # print(parent) 
        queue=[target] 
        visited=set()
        visited.add(target.val)
        while queue and k:
            nq=[]
            for temp in queue:
                if temp.left and temp.left.val not in visited:
                    visited.add(temp.left.val)
                    nq.append(temp.left) 
                if temp.right and temp.right.val not in visited:
                    visited.add(temp.right.val)
                    nq.append(temp.right) 
                if parent[temp] and parent[temp].val not in visited:
                    visited.add(parent[temp].val)
                    nq.append(parent[temp])
            queue=nq
            k-=1
        # print(queue)
        
        return [r.val for r in queue]
            
                