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
        while(root)
        {
            int cur = root->val;
            if(cur > p->val and cur > q->val) root = root->left;
            else if(cur < p->val and cur < q->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};