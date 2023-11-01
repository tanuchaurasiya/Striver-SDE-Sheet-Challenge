/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* help(vector<int>& preorder, vector<int>& inorder, int &preIdx, int inorStart, int inorEnd, unordered_map<int,int> &mp, int n){
        if((preIdx>= n)  || (inorStart>inorEnd))  
            return NULL; 
        
        int ele=preorder[preIdx++];
        TreeNode* root=new TreeNode(ele);
        int idx=mp[ele];
        
        root->left = help(preorder, inorder, preIdx, inorStart, idx-1, mp, n); 
        root->right = help(preorder,inorder, preIdx,idx+1, inorEnd,mp, n);  
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        unordered_map<int,int> mp; 
        
        int n=inorder.size(); 
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        int preIdx=0;
        return help(preorder, inorder, preIdx, 0, n-1, mp, n);
    }
};