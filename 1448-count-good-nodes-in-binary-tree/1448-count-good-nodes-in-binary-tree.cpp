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
    void help(TreeNode* root, int &ans, int maxx){
        if(root==NULL) return ;
        
        maxx=max(maxx, root->val); 
        
        if(root->val>=maxx) ans+=1;
        
        help(root->left, ans, maxx);
        help(root->right, ans, maxx);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        help(root, ans, INT_MIN);
        return ans;
    }
};