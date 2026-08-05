class Solution {
public:

    void solve(string &s, int n, int idx, string &dairy, vector<string> &ans, unordered_map<char, string> &f){
        if(idx==n){
            ans.push_back(dairy);
            return;
        }
        string choice = f[s[idx]];
        for(int j=0; j<choice.size(); j++){
            dairy.push_back(choice[j]);
            solve(s,n,idx+1,dairy,ans,f);
            dairy.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return{};
        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        vector<string> ans;
        int idx = 0;
        string diary = "";
        int n = digits.size();

        solve(digits,n,0,diary,ans,f);
        return ans;
    }
};