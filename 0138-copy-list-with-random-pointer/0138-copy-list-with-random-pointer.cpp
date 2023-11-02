/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) { 
        Node* t= head; 
        Node* newhead=new Node(101);
        Node* res=newhead;
        unordered_map<int, Node*> mp; 
        int c=1;
        while(t){
            newhead->next = new Node(t->val);  
            mp[c]=newhead->next;
            c++;
            newhead=newhead->next;
            t=t->next;
        } 
        
        res=res->next; 
        Node* final=res;
        t=head; 
        
        while(t){
            if(t->random==NULL){
                res->random=NULL;
                t=t->next;
                res=res->next;
            } 
            else{
            Node* t1=head; 
            int count=1; 
            
            while(t1!=t->random){
                count+=1; 
                t1=t1->next;
            } 
            
            res->random = mp[count];
            t=t->next;
            res=res->next;
            }
            
        }
        return final;
    }
        
};