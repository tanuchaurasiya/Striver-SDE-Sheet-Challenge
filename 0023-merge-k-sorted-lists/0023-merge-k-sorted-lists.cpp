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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        if(l2==NULL) 
            return l1; 
        if(l1==NULL) 
            return l2; 
        
        ListNode* res=NULL; 
        ListNode* temp=NULL;
        if (l1->val < l2->val){ 
            res=l1; 
            temp=l1; 
            l1=l1->next;
        } 
        else{
            res=l2; 
            temp=l2; 
            l2=l2->next;
        } 
        
        while(l1 && l2){
            if (l1->val < l2->val){  
            temp->next=l1; 
            l1=l1->next; 
            temp=temp->next;
            } 
        else{ 
            temp->next=l2; 
            l2=l2->next; 
            temp=temp->next; 
            } 
        } 
        
        while(l1){
            temp->next = l1; 
            temp=temp->next; 
            l1 = l1->next;
        } 
        
        while(l2){
            temp->next=l2; 
            l2=l2->next; 
            temp=temp->next;
        } 
        
        return res;
        
            
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {   
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1){
            return lists[0];
        }
        vector<ListNode* > mergeTwoListVector; 
        
        for(int i=0;i<lists.size();i=i+2){
            ListNode* l1 = lists[i];  
            ListNode* l2 = NULL;
            if(i+1<lists.size()) 
                l2 = lists[i+1]; 
           ListNode* merge = mergeTwoList(l1,l2); 
           mergeTwoListVector. push_back(merge);  
        }
        return mergeKLists(mergeTwoListVector); 
        
        
    }
};