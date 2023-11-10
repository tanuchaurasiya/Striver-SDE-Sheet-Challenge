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
private:
    int rootval;
public:
    bool help(TreeNode* root, long long lower, long long upper){
        // cout<<lower<<" "<<upper<<endl;
        if(root==NULL) return true; 
        
        if(lower<root->val && root->val<upper)
            return help(root->left, lower, root->val) && help(root->right, root->val, upper); 
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        rootval = root->val;
        return help(root, -1000000000000,1000000000000);
    }
};