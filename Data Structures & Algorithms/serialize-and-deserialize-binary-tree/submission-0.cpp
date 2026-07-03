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

class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode * root,string &s){
        if(root==NULL){
            s+="N ";
            return;
            //basically we need to backtrack
        }
        s+=to_string(root->val)+" ";
        preorder(root->left,s);
        preorder(root->right,s);

    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root,s);
        return s;
        
    }
    TreeNode * buildTree(stringstream & ss){
        string val;
        ss>>val;
        if(val=="N"){
            return NULL;
        }
        TreeNode * root=new TreeNode(stoi(val));
        root->left=buildTree(ss);
        root->right=buildTree(ss);
        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
        
    }
};
