class Solution {
public:
    unordered_map<int,int> dp;
    int solve(int n, int i){
        if(i==n) return 1;
        if(i>n) return 0;

        if(dp.find(i) != dp.end()){
            return dp[i];
        }

        int ans = solve(n,i+1) + solve(n,i+2);
        dp[i] = ans;
        return ans;
    }

    int climbStairs(int n) {
        int ans = solve(n,0);
        return ans;
    }
};