//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct node{
    int val;
    node* left;
    node* right;
    node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};

class Solution {
public:

    node* help(vector<int> &nums, int l ,int r){
        int m=(l+r)/2;
        if(l<=r){
        node* root= new node(nums[m]); 
        root->left = help(nums, l, m-1); 
        root->right = help(nums, m+1,r);
        return root;
        }
        return NULL;
    }
    
    void inor(node* root, vector<int> &inorder){
        if(root==NULL)
            return ; 
        inorder.push_back(root->val); 
        inor(root->left, inorder); 
        inor(root->right, inorder);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        node* root = help(nums, 0, nums.size()-1); 
        
        vector<int> inorder; 
        
        inor(root, inorder);
        return inorder;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends