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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int presum=0; 
        unordered_map<int,ListNode*> d;
        d[presum] = dummy;
        while(head){ 
            presum+=head->val ;
            if(d.find(presum)!=d.end()){
                ListNode* temp=d[presum]->next;
                int summ=presum;
                while(temp!=head){
                    summ+=temp->val;
                    d.erase(summ); 
                    temp=temp->next;
                }
                d[presum]->next=head->next;
            }
                
            else
                d[presum]=head;           
            head=head->next;
        }
        return dummy->next; 
    }
};