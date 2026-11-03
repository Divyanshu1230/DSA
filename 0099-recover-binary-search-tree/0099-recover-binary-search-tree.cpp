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
    int galat = 0;
    TreeNode* prev = NULL;
    TreeNode* g1_first = NULL, *g1_sec = NULL, *g2_first = NULL, *g2_sec = NULL;

    void fun(TreeNode* root){
        if(!root) return;
        fun(root->left); // left
    
        if(prev != NULL && root->val < prev->val){ // galat
            if(galat==0){
                g1_first = prev;
                g1_sec = root;
                galat++;
            } else {
                g2_first = prev;
                g2_sec = root;
                galat++;
            }
        }

        prev = root;
        fun(root->right);
    }

    void recoverTree(TreeNode* root) {
        
        fun(root);
        if(galat==1){
            swap(g1_first->val, g1_sec->val);
        } else if(galat==2) {
            swap(g1_first->val, g2_sec->val);
        }
    }
};