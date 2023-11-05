/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) { 
        
        ListNode* temp = head; 
        ListNode* res=head;
        int i=0;
        while(temp && temp->next){
            
            ListNode* t = temp->next->next; 
            ListNode* t1 = temp->next;
            temp->next = t; 
            t1->next = temp; 
            if(i==0){
                head = t1;
                res=temp;
                i+=1;
            }
            else{ 
                
                res->next = t1;
                res=temp;
                
            }
            temp = t;
        } 
        
        return head;
        
    }
};