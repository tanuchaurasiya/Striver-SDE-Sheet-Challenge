struct node{ 
    int val;
    int key;
    node* prev;
    node* next;
    node(int k,int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
    
};

class LRUCache {
private:
    unordered_map<int, node*> mp;
    node* head;
    node* tail;
    int size; 
    int currsize;
public:
    LRUCache(int capacity) { 
        size = capacity; 
        currsize = 0;
        head = new node(-1,-1);
        tail = new node(-1,-1); 
        head->next = tail;
        tail->prev = head;
        
    }
    
    void insert(int key, int value){
        node* newnode = new node(key, value); 
        newnode->next = head->next; 
        newnode->prev = head; 
        head->next->prev = newnode;
        head->next = newnode; 
        mp[key] = newnode;
    } 
    
    void del(int key){
        node* n = mp[key]; 
        n->prev->next = n->next; 
        n->next->prev = n->prev; 
        n->next = NULL;
        n->prev = NULL;
        delete n;  
        mp[key]=NULL;
        
    }
    
    int get(int key) { 
        if(mp[key]==NULL)
            return -1; 
        int value = mp[key]->val; 
        
        del(key);  
        insert(key,value); 
        
        return value;   
    }
    
    void put(int key, int value) { 
        if(mp[key]!=NULL){
            del(key);
            insert(key,value); 
            return;
        }
        if(size==currsize){ 
            node* n = tail->prev;
            int v = n->val;
            int k = n->key; 
            del(k);
            insert(key,value);
        }
        else{ 
            currsize+=1; 
            insert(key,value);
            
        } 
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */