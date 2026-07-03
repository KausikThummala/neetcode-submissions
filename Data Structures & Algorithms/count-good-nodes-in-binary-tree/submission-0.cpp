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
    int dfs(TreeNode * root,int max_so_far){
        if(!root) return 0;
        int count=0;
        if(root->val>=max_so_far) count++;
        max_so_far=max(root->val,max_so_far);
        count+=dfs(root->left,max_so_far);
        count+=dfs(root->right,max_so_far);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
        
    }
};
