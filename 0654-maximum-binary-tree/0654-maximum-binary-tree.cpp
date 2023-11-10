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
    int Largest(vector<int>&nums,int low,int high){
        int maxi  = INT_MIN;
        int ind = -1;
        for( int i=low;i<=high; i++){
            if(nums[i]>maxi){
               maxi  = nums[i];
               ind=i;
            }
        }
        return ind;
    }
    TreeNode*buildTree(vector<int>&nums,int low ,int high){
        if(low>high){
            return NULL;
        }
        int pos = Largest(nums,low,high);
        TreeNode*root = new TreeNode(nums[pos]);
        root->left= buildTree(nums,low,pos-1);
        root->right = buildTree(nums,pos+1,high);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        TreeNode*ans = buildTree(nums,low,high);
        return ans;
    }
};