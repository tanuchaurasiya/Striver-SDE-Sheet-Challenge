class node:
    def __init__(self):
        self.flag=0 
        self.children=[None]*26 
class Trie:
    def __init__(self):
        self.root=node()
    def insert(self, word: str) -> None: 
        temp=self.root
        n=len(word)
        for i in range(n):
            idx=ord(word[i])-97
            if temp.children[idx]==None:
                temp.children[idx]=node() 
            temp=temp.children[idx] 
        temp.flag=1
                
        

    def search(self, word: str) -> bool:
        temp=self.root
        n=len(word) 
        for i in range(n):
            idx=ord(word[i])-97
            if temp.children[idx]==None:
                return 0
            temp=temp.children[idx]  
        return temp.flag;
            
        

    def startsWith(self, prefix: str) -> bool:
        n=len(prefix)
        temp=self.root
        for i in range(n):
            idx=ord(prefix[i])-97
            if temp.children[idx]==None:
                return 0
            temp=temp.children[idx]  
        return 1

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)