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


class Solution
{
    public:
      
    void help(TreeNode* root, int height, vector<int> &visited, vector<int> &res){
        if (root==NULL) 
            return; 
        
        if(visited[height]==0){
            visited[height]=1; 
            res.push_back(root->val);
        } 
        
        
        help(root->right, height+1, visited, res); 
        help(root->left, height+1, visited, res);
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int> res; 
       vector<int> visited(100001, 0); 
       help(root, 0, visited, res); 
       return res;
    } 
};