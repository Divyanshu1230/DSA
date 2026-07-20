class Solution {
public:

    void getAllSubset(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubset) {
        if (i == nums.size()) {
            allSubset.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(nums[i]);
        getAllSubset(nums, ans, i + 1, allSubset);

        // Exclude current element
        ans.pop_back();
        getAllSubset(nums, ans, i + 1, allSubset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubset;

        getAllSubset(nums, ans, 0, allSubset);

        return allSubset;
    }
};