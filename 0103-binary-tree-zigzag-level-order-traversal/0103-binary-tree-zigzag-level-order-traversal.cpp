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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool rightToLeft = 1;
        vector<vector<int>> ans;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            int first=0, last=size-1;

            while(size--){
                TreeNode* t = q.front();
                q.pop();

                if(rightToLeft){
                    temp[first] = t->val;
                    first++;
                } else {
                    temp[last] = t->val;
                    last--;
                }
                if(t->left != NULL){
                    q.push(t->left);
                }
                if(t->right != NULL){
                    q.push(t->right);
                }
            }
            ans.push_back(temp);
            rightToLeft = 1-rightToLeft;
        }
        return ans;
    }
};