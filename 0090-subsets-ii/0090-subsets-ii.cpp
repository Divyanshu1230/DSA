class Solution {
public:

    void getAllSubset(vector<int>& nums, vector<int>& ans, int i,
                      vector<vector<int>>& allSubset) {

        if (i == nums.size()) {
            allSubset.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(nums[i]);
        getAllSubset(nums, ans, i + 1, allSubset);

        // Backtrack
        ans.pop_back();

        // Skip duplicates before the exclude call
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // Exclude current element
        getAllSubset(nums, ans, i + 1, allSubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        vector<vector<int>> allSubset;

        getAllSubset(nums, ans, 0, allSubset);

        return allSubset;
    }
};