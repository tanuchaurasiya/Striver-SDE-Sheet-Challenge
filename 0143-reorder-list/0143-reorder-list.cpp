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
    ListNode* reverse(ListNode* h){
        ListNode* curr = h;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    ListNode* middle(ListNode* h){
        ListNode* slow=h;
        ListNode* fast=h->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        } 
        return slow;
    }
    void reorderList(ListNode* head) {
        
        ListNode* mid = middle(head); 
        ListNode* midNext = mid->next; 
        mid->next=NULL;
        
        ListNode* midReverse = reverse(midNext); 
        
        ListNode* temp=head; 
        while(temp && midReverse){
            ListNode* tempNext = temp->next; 
            ListNode* midReverseNext = midReverse->next; 
            
            temp->next = midReverse;
            midReverse->next = tempNext; 
            
            temp=tempNext; 
            midReverse = midReverseNext;
        }
        
        
    }
};