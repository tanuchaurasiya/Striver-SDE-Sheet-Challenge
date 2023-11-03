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
    void RootToLeaf(TreeNode* root, string v, vector<string>&res)
    {
    
    if (root->left==NULL && root->right==NULL){ 
            res.push_back(v+to_string(root->val));
            return;
    } 
    else if (root->left!=NULL && root->right==NULL){
         RootToLeaf(root->left,v+to_string(root->val)+"->",res); 
    }
    
    else if (root->left==NULL && root->right!=NULL){
         RootToLeaf(root->right,v+to_string(root->val)+"->",res); 
    }
   
    else{
        RootToLeaf(root->left,v+to_string(root->val)+"->",res); 
        RootToLeaf(root->right,v + to_string(root->val)+"->",res);
    }
}
vector<string> binaryTreePaths(TreeNode* root) 
{
    string v;
    vector<string> res; 
    RootToLeaf(root,v,res);
    return res;
}

};