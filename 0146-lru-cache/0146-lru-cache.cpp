class node :
    def __init__(self,key,val):
        self.key=key
        self.val=val
        self.prev=None
        self.next=None 
        
class LRUCache:
    def __init__(self, capacity: int):
        self.head=node(-1,-1) 
        self.tail=node(-1,-1) 
        self.head.next=self.tail 
        self.tail.prev=self.head 
        self.map={}
        self.cap=capacity 

    def get(self, key: int) -> int: 
        if key not in self.map:
            return -1 
        existingnode = self.map[key] 
        ret=existingnode.val
        # print(ret)
        existingnode.prev.next  = existingnode.next 
        existingnode.next.prev = existingnode.prev 
        existingnode.prev=None 
        existingnode.next=None 
        del existingnode
                
        headnext=self.head.next 
        newnode=node(key,ret) 
        self.head.next=newnode 
        newnode.prev=self.head 
        newnode.next = headnext 
        headnext.prev=newnode
        self.map[key] = newnode 
        return ret

    def put(self, key: int, val: int) -> None: 
        if key in self.map:
                existingnode = self.map[key] 
                existingnode.prev.next  = existingnode.next 
                existingnode.next.prev = existingnode.prev 
                existingnode.prev=None 
                existingnode.next=None 
                del existingnode
                
                headnext=self.head.next 
                newnode=node(key,val) 
                self.head.next=newnode 
                newnode.prev=self.head 
                newnode.next = headnext 
                headnext.prev=newnode
                self.map[key] = newnode 
                
        elif self.cap>len(self.map): 
            if key not in self.map :
                headnext=self.head.next 
                newnode=node(key,val) 
                self.head.next=newnode 
                newnode.prev=self.head 
                newnode.next = headnext 
                headnext.prev=newnode
                self.map[key] = newnode 
                print(self.map[key], self.head.next.val)
            
        else: 
            deletednode = self.tail.prev 
            print(self.head.next.val,deletednode.val)
            deletednode.prev.next = self.tail 
            self.tail.prev=deletednode.prev 
            del self.map[deletednode.key]
            deletednode.prev=None
            deletednode.next=None 
            del deletednode
            
            headnext=self.head.next 
            newnode=node(key,val) 
            self.head.next=newnode 
            newnode.prev=self.head 
            newnode.next = headnext 
            headnext.prev=newnode
            self.map[key] = newnode
                
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)