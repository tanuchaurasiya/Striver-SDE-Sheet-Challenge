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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st; 
        for(int i=0;i<nums.size();i++){
            TreeNode* curr=new TreeNode(nums[i]);
            while(st.size() && st.top()->val<nums[i]){
                curr->left=st.top();
                st.pop();
            }
            if(st.size()){
                st.top()->right=curr;
            }
            st.push(curr);
        }
        while(st.size()!=1) st.pop();   
        return st.top();  
    }
};