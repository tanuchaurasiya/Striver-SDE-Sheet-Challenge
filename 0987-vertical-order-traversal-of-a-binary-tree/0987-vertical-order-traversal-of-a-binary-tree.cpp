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
    void help(TreeNode *root, int row, int col, unordered_map<int, vector<pair<int,int>>> &mp){  
        if (root==NULL) 
            return ;
        
        mp[col].push_back({row, root->val});  
        
        help(root->left, row+1, col-1, mp); 
        help(root->right, row+1, col+1, mp); 
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) { 
        
        unordered_map<int, vector<pair<int,int>>> mp;
        help(root, 0, 0, mp); 
        
        vector<int> keys; 
        
        for(auto i:mp){
            keys.push_back(i.first); 
            // cout<<i.first<<endl;
        } 
        sort(keys.begin(), keys.end()); 
        vector<vector<int>> res; 
        
        for(auto key:keys){
            vector<int> v; 
            sort(mp[key].begin(), mp[key].end());
            for(auto p: mp[key]){
                v.push_back(p.second);
            }  
            res.push_back(v);
        } 
        
        return res;
        
    }
};