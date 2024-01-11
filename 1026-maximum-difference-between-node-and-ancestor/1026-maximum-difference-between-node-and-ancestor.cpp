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
    pair<int,int> help(TreeNode* root, int &ans){
        if(root==NULL) return {1e6, 0}; //max, min
        
        pair<int,int> left = help(root->left, ans);
        pair<int,int> right = help(root->right, ans); 
        // cout<<"left"<<left.first<<" "<<left.second<<endl;
        // cout<<"right"<<right.first<<" "<<right.second<<endl;
        if(root->left || root->right)
            ans =  max(ans, max(abs(root->val-min(left.first, right.first)), abs(root->val - max(left.second, right.second))));
        // cout<<"ans="<<ans<<endl;
        // cout<<"return "<<min(root->val, left.first)<<" "<< max(root->val, right.second)<<endl;
        return {min(root->val, min(left.first, right.first)), max(root->val, max(left.second,right.second))};
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        pair<int,int> p = help(root, ans);
        return ans;
    }
};