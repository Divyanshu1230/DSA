class Solution {
public:
void solve(int open, int close, int n, vector<string> &ans, string curr){
    if(open ==n && close==n){
        ans.push_back(curr);
        return;
    }
    //open
    if(open<n){
        curr.push_back('(');
        solve(open+1, close, n, ans, curr);
        curr.pop_back();
    }
    //close
    if(close<open){
        curr.push_back(')');
        solve(open, close+1, n, ans, curr);
        curr.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(0, 0, n, ans, curr);
        return ans;
    }
};