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
int smallest(TreeNode* root){
    if(!root) return 0;
    while(root->left){
        root = root->left;
    }
    return root->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val > key){ // left
            root->left = deleteNode(root->left, key);
        } else if(root->val < key){ // right
            root->right = deleteNode(root->right, key);
        } else if(root->val == key){
            // delete node
            if(root->left != NULL && root->right != NULL){
                int replace = smallest(root->right);
                root->val = replace;
                root->right = deleteNode(root->right, replace);
            } else if(root->left){
                return root->left;
            } else if(root->right){
                return root->right;
            } else {
                return NULL;
            }
        }
        return root;
    }
};