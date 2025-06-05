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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()){
            vector<int> st;
           int t = q.size();
            
           for(int i=0;i<t;i++){
                TreeNode* nd = q.front();
                q.pop();
            if(nd->left != NULL){
                q.push(nd->left);
            }  
            if(nd->right != NULL){
                q.push(nd->right);
            }
           
            st.push_back(nd->val);
            }
            res.push_back(st);
        }
        return res;
    }
};