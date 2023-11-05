//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
Node* reverse(Node* h){
        Node* curr = h;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    Node* middle(Node* h){
        Node* slow=h;
        Node* fast=h->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        } 
        return slow;
    }
    void reorderList(Node* head)  {
        
        Node* mid = middle(head); 
        Node* midNext = mid->next; 
        mid->next=NULL;
        
        Node* midReverse = reverse(midNext); 
        
        Node* temp=head; 
        while(temp && midReverse){
            Node* tempNext = temp->next; 
            Node* midReverseNext = midReverse->next; 
            
            temp->next = midReverse;
            midReverse->next = tempNext; 
            
            temp=tempNext; 
            midReverse = midReverseNext;
        }
        
        
    }
    
      
    
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends