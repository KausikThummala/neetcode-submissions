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
    int diam=0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diam;

        
    }
    int maxDepth(TreeNode * root){
        if(!root){
            return 0;
        }
        int l_h=maxDepth(root->left);
        int r_h=maxDepth(root->right);
        diam=max(diam,l_h+r_h);
        return 1+max(l_h,r_h);
    }
};
