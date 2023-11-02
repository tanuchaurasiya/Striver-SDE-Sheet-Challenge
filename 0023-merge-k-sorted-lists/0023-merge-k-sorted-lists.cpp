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
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        vector<int> v; 
        for(int i=0;i<lists.size();i++){
            ListNode* t = lists[i];
            while (t){
                v.push_back(t->val);
                t=t->next; 
            }
        } 
        
        sort(v.begin(),v.end()); 
        
        ListNode* temp=new ListNode(0); 
        ListNode* res=temp;
        for(int i=0;i<v.size();i++) {
            temp->next = new ListNode(v[i]) ;
            temp=temp->next; 
        } 
        
        return res->next;
        
    }
};