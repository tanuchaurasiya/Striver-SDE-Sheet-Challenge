
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &childToPar, unordered_map<TreeNode*, int> &height, int h){ 
            if(root==NULL) 
                return; 
                
            height[root] = h;
            if(root->left) {
               childToPar[root->left] = root;  
               findParent(root->left, childToPar, height, h+1);
            }
              
            if(root->right) {
               childToPar[root->right] = root; 
               findParent(root->right, childToPar, height, h+1);
            } 
        } 
        
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
        {
            unordered_map<TreeNode*, TreeNode*> childToPar; 
            unordered_map<TreeNode*, int> height;
            findParent(root, childToPar, height, 0); 
            // for(auto i: childToPar){
            //     cout<<(i.first)->val<<" "<<(i.second)->val<<endl;
            // } 
            // cout<<"height\n";
            // for(auto i: height){
            //     cout<<(i.first)->val<< " "<<i.second<<endl;
            // }
            
            while(height[node1] > height[node2]){
                node1 = childToPar[node1]; 
            }
            
             while(height[node1] < height[node2]){
                node2 = childToPar[node2]; 
            }
            
            while(node1!=node2){ 
                node1 = childToPar[node1]; 
                node2 = childToPar[node2]; 
            } 
            
            return node1;
        }
    }
};