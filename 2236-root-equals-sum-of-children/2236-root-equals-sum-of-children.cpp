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
    int help(TreeNode* root, bool &res){
        if(root->left==NULL && root->right==NULL) return root->val; 
        
        int x = help(root->left, res); 
        int y = help(root->right, res); 
        
        if(x+y!=root->val) {
            res=false; 
            return 0;
            } 
        return x+y+root->val; 
        
    }
    bool checkTree(TreeNode* root) {
        bool res=true;
        int x = help(root, res); 
        return res;
    }
};