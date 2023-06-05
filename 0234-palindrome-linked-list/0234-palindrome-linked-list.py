# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool: 
        l=[]
        t=head 
        while(t!=None):
            l.append(t.val) 
            t=t.next
        if(l==l[::-1]):
            return 1
        return 0
        