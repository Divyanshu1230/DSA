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
    vector<vector<int>> ans;
    vector<int> diary;
    void solve(TreeNode* root, int sum, int tar){
        if(!root) return;
        sum=sum+root->val;
        diary.push_back(root->val);

        // leaf
        if(root->left==NULL && root->right==NULL){
            if(sum==tar){
                ans.push_back(diary);
                diary.pop_back();
                return;
            }
        }
        solve(root->left,sum,tar);
        solve(root->right,sum,tar);
        diary.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,0,targetSum);
        return ans;
    }
};