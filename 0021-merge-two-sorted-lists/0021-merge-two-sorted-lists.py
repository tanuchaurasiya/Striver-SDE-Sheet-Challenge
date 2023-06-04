# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:  
        h=ListNode() 
        res=h
        while(l1!=None and l2!=None): 
            if l1.val>l2.val:
                h.next=ListNode(l2.val) 
                h=h.next 
                l2=l2.next 
            elif l1.val<l2.val:
                h.next=ListNode(l1.val) 
                h=h.next 
                l1=l1.next 
            else:
                h.next=ListNode(l1.val) 
                h=h.next 
                h.next=ListNode(l2.val) 
                h=h.next 
                l1=l1.next 
                l2=l2.next 
        while l1!=None:
            h.next=ListNode(l1.val) 
            h=h.next 
            l1=l1.next 
        
        while l2!=None:
            h.next=ListNode(l2.val) 
            h=h.next 
            l2=l2.next 
            
        return res.next
        