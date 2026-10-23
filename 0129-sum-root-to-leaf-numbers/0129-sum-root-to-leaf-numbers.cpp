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
    int ans = 0;
    int solve(TreeNode* root, int sum){
        if(!root) return 0;
        sum=sum*10+root->val;

        // leaf
        if(root->left==NULL && root->right==NULL){
            ans+=sum;
        }
        solve(root->left,sum);
        solve(root->right,sum);
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};