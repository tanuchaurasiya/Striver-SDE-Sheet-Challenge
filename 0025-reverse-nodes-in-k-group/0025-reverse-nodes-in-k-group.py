# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class linklist:
    def __init__(self,head=None):
        self.head=None 
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
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        l=[]
        while(head!=None):
            l.append(head.val) 
            head=head.next
            
        # print(l) 
        leng=len(l)
        i=0 
        n=k
        while(i<leng): 
            start=i 
            end=k-1
            print(start,end)
            while(start<end):
                l[start],l[end]=l[end],l[start] 
                start+=1 
                end-=1 
            i=k
            if(i+n>leng):
                i=leng
            else:
                k=i+n
                
            print(l) 
        
        h=linklist()
        for x in l:
            h.insertend(x) 
            
        return h.showlist()
        