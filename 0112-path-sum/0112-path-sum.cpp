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
    bool ans = false;
    void solve(TreeNode* root, int sum, int targetSum){
        if(!root) return;
        sum+=root->val;
        // leaf
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans = true;
            }
        }
        // non-leaf
        solve(root->left,sum,targetSum);
        solve(root->right,sum,targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root,0,targetSum);
        return ans;
    }
};