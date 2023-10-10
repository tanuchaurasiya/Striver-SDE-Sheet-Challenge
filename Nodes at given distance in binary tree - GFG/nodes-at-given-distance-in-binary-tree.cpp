//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    
    void findPar(Node* root, unordered_map<int, Node*> &mp){ 
        if (root==NULL)
            return;
        if(root->left!=NULL) {
           mp[root->left->data]=root; 
           findPar(root->left, mp);
        }
           
           
        if(root->right!=NULL) {
           mp[root->right->data]=root; 
           findPar(root->right, mp);
            
        }
    } 
    
    Node* findTar(Node* root, int tar){
        if (root==NULL) 
            return NULL; 
        if(root->data==tar) 
            return root; 
        Node* x = findTar(root->left, tar);
        if (x) 
            return x; 
        x = findTar(root->right, tar);
        if(x) 
            return x; 
        return NULL;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        
        unordered_map<int,Node*> mp; 
        mp[root->data]=NULL;  
        findPar(root, mp); 
        // for(auto i:mp)
        //     cout<<i.first<<" "<<i.second<<endl;
        
        queue<pair<Node*, int>> q;   
        unordered_set<int> s;
       
        Node* tar = findTar(root, target);
        q.push({tar,k});
         s.insert(tar->data);
        vector<int> res;
        while(!q.empty()){ 
            auto a = q.front(); 
            Node* temp=a.first;
            k=a.second;
            q.pop();  
            if(k==0) 
                res.push_back(temp->data); 
            //cout<<"temp and k="<<temp->data<<" "<<k<<endl;
            if(k!=0 && temp->left && s.find(temp->left->data)==s.end()) {
               q.push({temp->left,k-1});  
               s.insert(temp->left->data); 
               //cout<<"left="<<temp->left->data<<endl;
            }
            if(k!=0 && temp->right && s.find(temp->right->data)==s.end()) {
               q.push({temp->right, k-1});  
               s.insert(temp->right->data);
            //   cout<<"right="<<temp->right->data<<endl;
            }
             
            if(k!=0 && mp[temp->data]  && s.find(mp[temp->data]->data)==s.end()) { 
                q.push({mp[temp->data],k-1});
                s.insert(mp[temp->data]->data); 
                //cout<<"parent="<<mp[temp->data]->data<<endl;
            }
            
        }  
        sort(res.begin(),res.end());
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends