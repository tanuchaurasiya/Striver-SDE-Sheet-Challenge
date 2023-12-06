//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* findMiddle(Node* head){
        if(head==NULL) return head; 
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    } 
    
    Node* reverse(Node* head){
        if(head==NULL) return NULL;
        
        Node* curr=head;
        Node* prev = NULL;
        Node* next=NULL;
        while(curr){
            next=curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        Node* h = head;
        Node* mid = findMiddle(h);
        Node* n1 = head;
        Node* n2 = mid->next; 
        mid->next=NULL; 
        n2 = reverse(n2); 
        
        while(n1 && n2){
            if(n1->data != n2->data) return false;
            n1= n1->next;
            n2= n2->next;
        }
        return true;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends