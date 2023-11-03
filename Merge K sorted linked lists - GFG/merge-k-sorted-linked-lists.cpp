//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    Node* mergeTwoList(Node* l1, Node* l2){
        if(l2==NULL) 
            return l1; 
        if(l1==NULL) 
            return l2; 
        
        Node* res=NULL; 
        Node* temp=NULL;
        if (l1->data < l2->data){ 
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
            if (l1->data < l2->data){  
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
    
    Node* help(vector<Node*> lists)
    {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1){
            return lists[0];
        }
        vector<Node* > mergeTwoListVector; 
        
        for(int i=0;i<lists.size();i=i+2){
            Node* l1 = lists[i];  
            Node* l2 = NULL;
            if(i+1<lists.size()) 
                l2 = lists[i+1]; 
           Node* merge = mergeTwoList(l1,l2); 
           mergeTwoListVector. push_back(merge);  
        }
        return help(mergeTwoListVector);
    }
    Node * mergeKLists(Node *arr[], int K) {   
        vector<Node*> v;
        for(int i=0;i<K;i++){
            v.push_back(arr[i]);
        }
        
        return help(v);
         
    }
    
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends