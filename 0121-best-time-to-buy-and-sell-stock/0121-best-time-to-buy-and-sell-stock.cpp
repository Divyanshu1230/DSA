class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int maxProfit = 0;
        if(n==0){
            return maxProfit;
        }
        int rG = arr[n-1];

        for(int i=n-2; i>=0; i--){
            int p = rG - arr[i];
            maxProfit=max(maxProfit, p);
            rG = max(rG, arr[i]);
        }
        return maxProfit;
    }
};