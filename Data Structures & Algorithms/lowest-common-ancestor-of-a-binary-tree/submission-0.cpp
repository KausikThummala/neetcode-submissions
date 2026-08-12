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
        //here if root==NULL || root==p || root==q then return root
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode * left1=lowestCommonAncestor(root->left,p,q);
        TreeNode * right1=lowestCommonAncestor(root->right,p,q);

        if(left1!=NULL && right1!=NULL) return root;
        return (left1!=NULL) ? left1: right1;
        
    }
};