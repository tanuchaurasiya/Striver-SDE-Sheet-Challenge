'''
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
'''


# This function finds predecessor and successor of key in BST.
# It sets pre and suc as predecessor and successor respectively
class Solution:
    def __init__(self):
        self.pre=10**9
        self.suc=-10**9
    def findPreSuc(self, root, pre, suc, key):
        def helppre(root,key):
            if root==None:
                return 
            if root.key>=key:
                helppre(root.left,key) 
            elif root.key<key:
                if abs(self.pre-key) > abs(key-root.key):
                    self.pre=root.key
                # print("pre",self.pre)
                helppre(root.right,key) 
        def helpsuc(root,key):
            if root==None:
                return 
            if root.key>key:
                if abs(self.suc-key) > abs(key-root.key):
                    self.suc=root.key
                # print("suc",self.suc)
                helpsuc(root.left,key) 
            elif root.key<=key:
                helpsuc(root.right,key) 
        

        helppre(root,key)
        helpsuc(root,key)
        if self.pre==10**9:
            self.pre=-1
        if self.suc==-10**9:
            self.suc=-1
        return [Node(self.pre),Node(self.suc)]


#{ 
 # Driver Code Starts
import queue

# BST Node
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def buildTree(ip):
    # Corner Case
    if len(ip) == 0 or ip[0] == 'N':
        return None

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    q = queue.Queue()
    q.put(root)

    # Starting from the second element
    i = 1
    while not q.empty() and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.get()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.right)

        i += 1

    return root


# Driver program to test above functions
t = int(input())
for _ in range(t):
    s = input()
    root = buildTree(s.split())
    k = int(input())
    pre = None
    succ = None
    ob = Solution()
    pre, succ = ob.findPreSuc(root, pre, succ, k)
    if pre:
        print(pre.key, end=' ')
    else:
        print(-1, end=' ')
    if succ:
        print(succ.key, end=' ')
    else:
        print(-1, end=' ')
    print()

# } Driver Code Ends