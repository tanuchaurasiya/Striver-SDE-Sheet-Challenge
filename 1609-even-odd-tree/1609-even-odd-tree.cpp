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
    
    bool levelOrder(TreeNode* root) { 
        if(root==NULL) 
            return 1;
        vector<TreeNode*> temp; 
        temp.push_back(root);  
        int idx=0;
        while(temp.size()>0){   
            vector<TreeNode*> temp1; 
            int flag=0;
            int prev;
            for(auto c: temp){ 
                cout<<flag<<" "<<idx<<" "<<prev<<" "<<c->val<<endl;
                if(flag==0){
                    if(idx%2==0  && ((c->val)%2!=1)) return false; 
                    if(idx%2==1  && ((c->val)%2!=0)) return false;
                    prev = c->val;
                    flag=1;
                }
                else{
                    if(idx%2==0) {
                        if(((c->val)%2 !=1) || (prev>=c->val)) return false;
                        else prev = c->val;
                    }
                    else {
                        if(((c->val) %2 !=0) || (prev<=c->val)) return false;
                        else prev = c->val;
                    }
                }
                if(c->left) 
                    temp1.push_back(c->left); 
                if(c->right) 
                    temp1.push_back(c->right);  
                
            }  
            idx++;
            temp=temp1; 
        } 
        
        
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) {
        return levelOrder(root);
    }
};