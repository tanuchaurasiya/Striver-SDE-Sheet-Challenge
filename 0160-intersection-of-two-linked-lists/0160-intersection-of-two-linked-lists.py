# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, A: ListNode, B: ListNode) -> ListNode:
        s=set()
        while(A!=None):
            s.add(A)
            A=A.next  
        # print(s)
        while(B!=None):
            if(B in s):
                return B
            B=B.next 
        