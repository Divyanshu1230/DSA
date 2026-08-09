class Solution {
public:
    void solve(int k,int n, int idx, int sum, vector<int> &diary, vector<vector<int>> &ans){
        if(sum==n && k==0){ // base case
            ans.push_back(diary);
            return;
        }
        if(sum>n) return;

        for(int i=idx; i<=9; i++){
            if(i>n) break;
            diary.push_back(i);
            solve(k-1,n,i+1,sum+i,diary,ans);
            diary.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> diary;
        vector<vector<int>> ans;

        solve(k,n,1,0,diary, ans);
        return ans;
    }
};