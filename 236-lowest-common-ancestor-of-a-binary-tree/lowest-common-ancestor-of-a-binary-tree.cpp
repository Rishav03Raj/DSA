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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        dfs(root,p,v1);
        dfs(root,q,v2);
        TreeNode* ans;
        int n = min(v1.size(),v2.size());
        for(auto it:v1){
            cout<<it->val<<" ";
        }
        cout<<endl;
        for(auto it:v2){
            cout<<it->val<<" ";
        }
        
        for(int i=n-1;i>=0;i--){
            if(v1[i]==v2[i]){
                ans= v1[i];
                break;
            }
        }
        return ans;
    }
    bool dfs(TreeNode* root,TreeNode* p,vector<TreeNode*> &v){
        if(!root) return false;
        v.push_back(root);
        if(root==p) return true;
        if((dfs(root->left,p,v) || dfs(root->right,p,v))) return true;
        v.pop_back();
        return false;

    }
};