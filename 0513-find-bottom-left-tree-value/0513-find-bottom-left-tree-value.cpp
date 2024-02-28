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
    void help(TreeNode* root, int depth, int &max_depth, int &node){
        if(root==NULL) return; 
        if(root->left==NULL && root->right==NULL){
            if(depth>max_depth){
                max_depth=depth;
                node=root->val;
            }
        }
        
        help(root->left, depth+1, max_depth, node);
        help(root->right, depth+1, max_depth, node);
    }
    int findBottomLeftValue(TreeNode* root) {
        int max_depth=0;
        int depth=1;
        int node=-1;
        help(root, depth, max_depth, node);
        return node;
    }
};