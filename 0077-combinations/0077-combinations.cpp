class Solution {
public:
    void solve(int start, int n, int k, vector<int> &diary, vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(diary);
            return;
        }
        for(int i=start; i<=n; i++){
            diary.push_back(i);
            solve(i+1,n,k-1,diary,ans);
            diary.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> diary;
        vector<vector<int>> ans;

        solve(1,n,k,diary,ans);
        return ans;
    }
};