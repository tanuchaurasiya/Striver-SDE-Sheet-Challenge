#User function Template for python3


class Solution: 
    
    def __init__(self):
        self.c=0
        
    def traverse(self,root):
        if root==None:
            return []
        else:
            return self.traverse(root.left)+[root.data]+self.traverse(root.right)
   
    def correctBST(self, root):
        l=self.traverse(root) 
        ln=l.copy()
        l.sort()
        a=0
        b=0
        for i in range(len(l)):
            if l[i]!=ln[i]:
                a=l[i]
                b=ln[i] 
                break  
        # print(a,b,l,ln)        
        def fun(root):
            if root!=None:
                if root.data==a:
                    root.data=b
                    self.c+=1 
                elif root.data==b:
                    root.data=a 
                    self.c+=1 
                elif self.c==2:
                    return 
                else:
                    pass
                fun(root.left)
                fun(root.right)
        fun(root)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque

# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root

def isBST(n,lower,upper):
    if n is None:
        return True
    if n.data<=lower or n.data>=upper:
        return False
    return isBST(n.left,lower,n.data) and isBST(n.right,n.data,upper)

def compare(a,b,mismatch):
    if a is None and b is None:
        return True
    if a is None or b is None:
        return False
    
    if a.data != b.data:
        mismatch.append( (a.data,b.data) )
    
    return compare(a.left,b.left,mismatch) and compare(a.right,b.right,mismatch)

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        s=input()
        
        root = buildTree(s)
        duplicate = buildTree(s)
        obj = Solution()
        obj.correctBST(root)
        
        # check 1: is tree now a BST
        if not isBST(root,0,1000000000):
            print(0)
            continue
        
        # check 2: comparing with duplicate tree
        
        mismatch = []
        # a list to store data of mismatching nodes
        
        if not compare(root, duplicate, mismatch):
            # false output from this function indicates change in tree structure
            print(0)
        
        if len(mismatch)!=2 or mismatch[0][0]!=mismatch[1][1] or mismatch[0][1]!=mismatch[1][0]:
            print(0)
        else:
            print(1)

# } Driver Code Ends