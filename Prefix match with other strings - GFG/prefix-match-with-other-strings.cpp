//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

struct node{
     node *arr[26]; 
    int prefixcount=0;
};
class Solution{   
private:
    node *root1;
public:
    Solution(){
        root1=new node();
    }
    void insert(string s)
    {
        node *root=root1;
        for (int i=0;i<s.length();i++)
        {
            int idx = int(s[i]) - 97;
            if (!root->arr[idx]) 
            {
                root->arr[idx] = new node(); 
            }
            root=root->arr[idx];
            root->prefixcount+=1;
        }
    } 
    
    int countprefix(string s) {
        node *root=root1;
        for (int i=0;i<s.length();i++)
        {
            int idx = int(s[i]) - 97;
            if (!root->arr[idx]) 
            {
                return 0;
            } 
            else{
                root=root->arr[idx]; 
            }
        }
        return root->prefixcount;
    }
    int klengthpref(string arr[], int n, int k, string str){    
        for(int i=0;i<n;i++)
            insert(arr[i]);
        string pre=""; 
        for(int i=0;i<k;i++) 
            pre+=str[i];
        return countprefix(pre);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends