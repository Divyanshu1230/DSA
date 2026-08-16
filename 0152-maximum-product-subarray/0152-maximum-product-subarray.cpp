class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxend = nums[0];
        int minend = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++){
            int v1 = maxend*nums[i];
            int v2 = minend*nums[i];
            int v3 = nums[i];

            minend = min(v1, min(v2,v3));
            maxend = max(v1, max(v2,v3));
            ans = max(ans, max(minend, maxend));
        }
        return ans;
    }
};