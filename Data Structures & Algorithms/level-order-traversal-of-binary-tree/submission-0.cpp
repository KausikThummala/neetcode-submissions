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
        //for level order traversal use a queue
        //implement bfs
        vector <vector<int>> res;
        queue <TreeNode *> dq;
        dq.push(root);
        while(!dq.empty()){
            int qLen=dq.size();
            vector <int> level;
            for(int i=0;i<qLen;i++){
                TreeNode * node=dq.front();
                dq.pop();
                if(node){
                    level.push_back(node->val);
                    if(node->left){
                        dq.push(node->left);
                    }
                    if(node->right){
                        dq.push(node->right);
                    }
                }
            }
            if(!level.empty()){
                res.push_back(level);
            }
        }
        return res;
    }
};
