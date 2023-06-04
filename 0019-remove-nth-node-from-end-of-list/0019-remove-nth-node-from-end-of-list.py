# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]: 
        length=0
        t=head
        while(t!=None):
            length+=1
            t=t.next
        if(length==1):
            return None 
        if(length==n):
            head=head.next 
            return head
        num=length-n-1 
        t1=head
        while(num>0):
            t1=t1.next 
            num-=1 
        # print(t1.val) 
        if(t1.next.next==None): 
            print("K")
            t1.next=None
            return head            
        t1.next=t1.next.next 
        return head