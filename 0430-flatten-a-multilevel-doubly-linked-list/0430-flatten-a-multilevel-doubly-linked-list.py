"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def __init__(self):  
        self.head=Node(0,None,None,None)  
        self.op=self.head  
        self.k=[]
    def helper(self,h): 
        while h:
            if h.child!=None:
                self.head.next=h 
                h.child.prev=h  
                if h.next!=None:
                    self.k.append(h.next)
                h.next=h.child 
                h.child=None
                self.helper(h.child)   
            else: 
                self.head.next=h 
                h=h.next  
                self.head=self.head.next    
                
        return self.op 
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]': 
        
        res=self.helper(head).next 
        for x in self.k[-1::-1]: 
            x.prev=self.head
            while(x!=None):
                self.head.next=x 
                x=x.next 
                self.head=self.head.next 
            
        return res
        