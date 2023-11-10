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
    
    TreeNode* bstFromPreorder(vector<int>& preorder) { 
        vector<int> inorder;
        for(int i=0;i<preorder.size();i++)
            inorder.push_back(preorder[i]);
        sort(inorder.begin(), inorder.end());
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        int preIdx=0;
        return help(preorder, inorder, preIdx, 0, inorder.size()-1, mp, inorder.size());
        
    }
};