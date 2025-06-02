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
    void inro(TreeNode* root,vector<int> &v){

        if(!root) return ;
        inro(root->left,v);
        v.push_back(root->val);
        inro(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inro(root,v);
        return v; 
    }
};