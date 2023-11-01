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
    vector<vector<int>> levelOrder(TreeNode* root) { 
        vector<vector<int>> ans;
        if(root==NULL) 
            return ans;
        vector<TreeNode*> temp; 
        temp.push_back(root);  
        vector<int> v;
        while(temp.size()>0){   
            vector<TreeNode*> temp1;  
            for(auto c: temp){ 
                v.push_back(c->val);
                if(c->left) 
                    temp1.push_back(c->left); 
                if(c->right) 
                    temp1.push_back(c->right); 
            } 
            ans.push_back(v); 
            v.clear();
            temp=temp1; 
        } 
        
        
        return ans;
    }
};