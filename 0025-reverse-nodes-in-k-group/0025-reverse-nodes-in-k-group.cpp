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
    ListNode* help(ListNode* head, int k, int n){
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL; 
        int count=0; 
        if(n<k) 
            return head;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next; 
            count+=1;
        } 
        
        if(next!=NULL)
        {
            head->next = help(next, k, n-k);
        } 
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) { 
        ListNode* h =head; 
        int n=0;
        while(h){
            n+=1;
            h=h->next;
        }
        return help(head,k,n);
    }
};