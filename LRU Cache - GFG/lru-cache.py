class node :
    def __init__(self,key,val):
        self.key=key
        self.val=val
        self.prev=None
        self.next=None 
        
class LRUCache:
    def __init__(self, capacity):
        self.head=node(-1,-1) 
        self.tail=node(-1,-1) 
        self.head.next=self.tail 
        self.tail.prev=self.head 
        self.map={}
        self.cap=capacity 

    def get(self, key):
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

    def set(self, key,val):
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
                # print(self.map[key], self.head.next.val)
            
        else: 
            deletednode = self.tail.prev 
            # print(self.head.next.val,deletednode.val)
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


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        cap = int(input())  # capacity of the cache
        qry=int(input())  #number of queries
        a = list(map(str, input().strip().split()))  # parent child info in list
        
        lru=LRUCache(cap)
        
       
        i=0
        q=1
        while q<=qry:
            qtyp=a[i]
            
            if qtyp=='SET':
                lru.set(int(a[i+1]),int(a[i+2]))
                i+=3
            elif qtyp=='GET':
                print(lru.get(int(a[i+1])),end=' ')
                i+=2
            q+=1
        print()
# } Driver Code Ends