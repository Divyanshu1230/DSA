class Solution {
public:

    // unordered_map<int,int> dp;
    int fib(int n) {
        // if(n==0 || n==1) return n; // base case

        // if(dp.find(n) != dp.end()){ // map me hai
        //     return dp[n];
        // }

        // int ans = fib(n-1)+fib(n-2);
        // dp[n] = ans;
        // return ans;

        // tubular-iterative with space opt 
        if(n==0 || n==1) return n;
        
        int prev = 1, prev_prev = 0;
        int ans;
        for(int i=2; i<=n; i++){
            ans = prev + prev_prev;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
};