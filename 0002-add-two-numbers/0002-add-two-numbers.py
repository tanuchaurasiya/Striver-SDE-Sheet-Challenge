# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class linklist: 
    def __init__(self,head=None):
        self.head=head 
        
    def insertend(self,val): 
        newnode=ListNode(val)
        if(self.head==None): 
            self.head=newnode
        else:
            t=self.head  
            while(t.next!=None): 
                t=t.next
            t.next=newnode 
            
    def showlist(self):
        return self.head
class Solution:
    def addTwoNumbers(self, first: Optional[ListNode], second: Optional[ListNode]) -> Optional[ListNode]:
               
        h=linklist()
        summ=0
        carry=0
        while(first!=None and second!=None):
            summ=first.val+second.val
            h.insertend((carry+summ)%10)
            carry=(summ+carry)//10
            first=first.next
            second=second.next 
            
        while(first!=None):
            h.insertend((carry+first.val)%10)
            carry=(first.val+carry)//10
            first=first.next
        
        while(second!=None):
            # print(carry,second.val)
            h.insertend((carry+second.val)%10)
            carry=(second.val+carry)//10
            # print(carry)
            second=second.next
        if(carry!=0):
            h.insertend(carry)
        return h.showlist()
        