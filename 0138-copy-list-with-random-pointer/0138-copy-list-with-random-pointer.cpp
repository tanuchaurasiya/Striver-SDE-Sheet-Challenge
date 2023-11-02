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
        while(t){
            newhead->next = new Node(t->val); 
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
            int count=0; 
            
            while(t1!=t->random){
                count+=1; 
                t1=t1->next;
            } 
            
            
            Node* temp = final;
            while(count){
                temp=temp->next;
                count--;
                
            }  
            res->random = temp;
            t=t->next;
            res=res->next;
            }
            
        }
        return final;
    } 
        
};