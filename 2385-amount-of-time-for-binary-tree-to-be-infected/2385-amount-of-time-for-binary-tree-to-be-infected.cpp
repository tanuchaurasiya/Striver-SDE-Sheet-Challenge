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
    void storeParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        if(root==NULL) return;
        if(root->left)
            parent[root->left] = root;
        if(root->right)
            parent[root->right] = root;
        storeParent(root->left, parent);
        storeParent(root->right, parent);
    }
    TreeNode* findStart(int start, TreeNode* root){ 
        if(root==NULL) return NULL;
        
        if(root->val==start) return root;
        
        TreeNode* l = findStart(start, root->left);
        if(l) return l;
        
        TreeNode* r = findStart(start, root->right);
        if(r) return r;
        return NULL;
        
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        storeParent(root, parent);
        queue<pair<TreeNode*, int>> q;
        TreeNode* x = findStart(start, root);
        q.push({x, 0});
        
        unordered_map<int,int> visited;
        visited[start]=1;
        int res=0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int time = q.front().second;
            q.pop();
            if(time > res)
                res=time;
            TreeNode* par = parent[node];
            TreeNode* chi1 = node->left;
            TreeNode* chi2 = node->right;
            if(par && visited[par->val]==0) {
                visited[par->val] = 1;
                q.push({par,time+1});
            }
            
            if(chi1 && visited[chi1->val]==0) {
                visited[chi1->val] = 1;
                q.push({chi1, time+1});
            }
            
            if(chi2 && visited[chi2->val]==0) {
                visited[chi2->val] = 1;
                q.push({chi2, time+1});
            }
            
        }
        return res;
    }
};