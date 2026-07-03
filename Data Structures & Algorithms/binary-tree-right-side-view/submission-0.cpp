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
    vector<int> rightSideView(TreeNode* root) {
        //similar to bfs
        //but we have to maintain the right most node in each level
        queue <TreeNode *> dq;
        vector <int> res;
        dq.push(root);
        while(!dq.empty()){
            int qLen=dq.size();
            TreeNode * right_side=NULL;
            for(int i=0;i<qLen;i++){
                TreeNode * node=dq.front();
                dq.pop();
                if(node){
                    right_side=node;
                    if(node->left){
                        dq.push(node->left);
                    }
                    if(node->right){
                        dq.push(node->right);
                    }
                }
                
            }
            if(right_side){
                    res.push_back(right_side->val);
                }
        }
        return res;
        
    }
};
