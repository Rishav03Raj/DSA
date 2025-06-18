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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int dt=-1,cn=0;
        dfs(root,k,cn,dt);
        return dt;
    }
    void dfs(TreeNode* root,int k,int &cn,int &dt){
            if(!root) return ;
            dfs(root->left,k,cn,dt);
            cn++;
            if(cn==k){
                dt = root->val;
                return ;
            } 
            dfs(root->right,k,cn,dt);
    }
};