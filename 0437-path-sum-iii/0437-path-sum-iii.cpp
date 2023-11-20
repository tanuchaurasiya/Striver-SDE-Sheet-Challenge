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
    void help(TreeNode* root, long long int sum, unordered_map<long long int,long long int> &mp, long long int &ans, int k){
        if(root==NULL)
            return;
        sum+=root->val;
        if(sum==k)
            ans+=1;
        if(mp.find(sum-k)!=mp.end())
            ans+=mp[sum-k];
        
        mp[sum]++;
        help(root->left, sum, mp, ans, k);
        help(root->right, sum ,mp, ans, k);
        mp[sum]--;
        
    }
    int pathSum(TreeNode* root, int k)
    {
        long long int ans=0;
        long long int sum=0;
        unordered_map<long long int,long long int> mp;
        help(root, sum, mp, ans, k);
        return ans;
        
    }
     
};