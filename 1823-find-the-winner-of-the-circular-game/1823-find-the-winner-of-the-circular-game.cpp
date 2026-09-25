class Solution {
public:
    int findWinnerIdx(int n, int k){
        if(n==1) return 0; // base case

        int idx = findWinnerIdx(n-1, k);
        idx = (idx+k)%n; // orginal idx in orginal array
        return idx;
    }
    int findTheWinner(int n, int k) {
        int ans = findWinnerIdx(n, k);
        return ans+1;
    }
};