class Solution {
public:
    void solve(vector<int> &a, int target, int idx, int sum, vector<int> &diary, vector<vector<int>> &ans){
        int n=a.size();
        if(idx==n || sum>target) return;
        if(sum==target){
            ans.push_back(diary);
            return;
        }
        //choice1 (nehi lena)
        solve(a, target, idx+1, sum, diary, ans);

        //choice 2
        if(a[idx]+sum <= target){
            diary.push_back(a[idx]);
            sum+=a[idx];
            solve(a, target, idx, sum, diary, ans);
            diary.pop_back();
            sum-=a[idx];
        }


    }

    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<int> diary;
        vector<vector<int>> ans;

        solve(a,target, 0, 0, diary, ans);
        return ans;
    }
};