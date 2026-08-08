class Solution {
public:

    void solve(vector<int> &a, int tar, int n, int idx, vector<int> &diary, vector<vector<int>> &ans){
        if(tar<0) return;
        if(tar==0){
            ans.push_back(diary);
            return;
        }
        for(int i=idx; i<n; i++){
            if(i>idx && a[i]==a[i-1]){
                continue;
            }
            diary.push_back(a[i]);
            solve(a,tar-a[i], n,i+1,diary,ans);
            diary.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& a, int tar) {
        vector<int> diary;
        vector<vector<int>> ans;
        sort(a.begin(), a.end());

        solve(a,tar,a.size(),0,diary,ans);
        return ans;
    }
};