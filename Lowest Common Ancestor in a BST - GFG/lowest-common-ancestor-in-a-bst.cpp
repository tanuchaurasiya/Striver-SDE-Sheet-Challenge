//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* find(Node* root, int n){
            if(root==NULL) 
                return NULL; 
            
            if(root->data==n)
                return root; 
            
            Node* left = find(root->left,n); 
            if(left)
                return left;
            Node* right = find(root->right, n); 
            
            if(right) 
                return right;
            
            return NULL;
        } 
        
        void findParent(Node* root, unordered_map<Node*, Node*> &childToPar, unordered_map<Node*, int> &height, int h){ 
            if(root==NULL) 
                return; 
                
            height[root] = h;
            if(root->left) {
               childToPar[root->left] = root;  
               findParent(root->left, childToPar, height, h+1);
            }
              
            if(root->right) {
               childToPar[root->right] = root; 
               findParent(root->right, childToPar, height, h+1);
            } 
        } 
        
        Node* LCA(Node *root, int n1, int n2)
        {
            Node* node1 = find(root, n1); 
            Node* node2 = find(root, n2); 
            unordered_map<Node*, Node*> childToPar; 
            unordered_map<Node*, int> height; 
            
            findParent(root, childToPar, height, 0); 
            
            while(height[node1] > height[node2]){
                node1 = childToPar[node1]; 
            }
            
             while(height[node1] < height[node2]){
                node2 = childToPar[node2]; 
            }
            
            while(node1!=node2){ 
                node1 = childToPar[node1]; 
                node2 = childToPar[node2]; 
            } 
            return node1;
        }

};


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends