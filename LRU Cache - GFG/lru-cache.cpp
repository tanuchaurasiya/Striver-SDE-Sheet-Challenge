//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct node{
    int key;
    int val; 
    node* prev;
    node* next;
};
class LRUCache {
private: 
    unordered_map<int, node*> map;
    int cap;
    node* head;
    node* tail;
    
public:
    LRUCache(int capacity) {
        cap=capacity;
        head = new node();
        head->key=-1;
        head->val=-1; 
        
        tail= new node(); 
        tail->key=-1;
        tail->val=-1; 
    
        head->next=tail;
        tail->prev=head; 
    
    }
    
    int GET(int key) {
        if(map.find(key)==map.end())
            return -1;
        
        node* existingnode = map[key] ;
        int ret=existingnode->val;
        existingnode->prev->next  = existingnode->next ;
        existingnode->next->prev = existingnode->prev ;
        existingnode->prev=NULL;
        existingnode->next=NULL; 
        delete existingnode;
                
        node* headnext=head->next;
        node* newnode=new node();
        newnode->key=key;
        newnode->val=ret;
        head->next=newnode;
        newnode->prev=head;
        newnode->next = headnext; 
        headnext->prev=newnode;
        map[key] = newnode; 
        return ret;
    }
    
    void SET(int key, int val) { 
        if(map.find(key)!=map.end())
        {
            node *existingnode = map[key]; 
            existingnode->prev->next  = existingnode->next; 
            existingnode->next->prev = existingnode->prev ;
            existingnode->prev=NULL;
            existingnode->next=NULL;
            delete existingnode;
                
            node *headnext=head->next;
            node *newnode=new node();
            newnode->key=key;
            newnode->val=val;
            head->next=newnode ;
            newnode->prev=head ;
            newnode->next = headnext ;
            headnext->prev=newnode;
            map[key] = newnode; 
        } 
        
        else if (cap>map.size()){ 
            
            node *headnext=head->next; 
            node *newnode=new node();
            newnode->key=key;
            newnode->val=val;
            head->next=newnode; 
            newnode->prev=head;
            newnode->next = headnext; 
            headnext->prev=newnode;
            map[key] = newnode;
        }
            
        else{ 
            node *deletednode = tail->prev;
            deletednode->prev->next = tail;
            tail->prev=deletednode->prev;
            map.erase(deletednode->key); 
            deletednode->prev=NULL;
            deletednode->next=NULL;
            delete deletednode;
            
            node* headnext=head->next;
            node* newnode=new node();
            newnode->key=key;
            newnode->val=val;
            head->next=newnode; 
            newnode->prev=head ;
            newnode->next = headnext ;
            headnext->prev=newnode;
            map[key] = newnode;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends