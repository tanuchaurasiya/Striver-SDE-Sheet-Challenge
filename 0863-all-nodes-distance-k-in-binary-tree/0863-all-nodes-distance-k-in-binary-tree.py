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
        queue=[[target, k]] 
        visited=set()
        visited.add(target.val)
        res=[]
        while queue:
            tar, dist = queue.pop(0)
            if(dist==0):
                res.append(tar.val)
            elif(dist>0):
                if(parent[tar] and parent[tar].val not in visited):
                    queue.append([parent[tar], dist-1])
                    visited.add(parent[tar].val)
            
                if tar.left and tar.left.val not in visited:
                    visited.add(tar.left.val)
                    queue.append([tar.left, dist-1]) 
                if tar.right and tar.right.val not in visited:
                    visited.add(tar.right.val)
                    queue.append([tar.right, dist-1]) 
            
        return res
            
                