class Solution {
public:

    // max subarray sum
    int maxSum(vector<int>& nums){
        int n=nums.size();
        int bestending = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            bestending = max(v1, v2);
            ans = max(ans, bestending);
        }
        return ans;
    }

    int circularSum(vector<int>& nums){
        int n = nums.size();
        // Sum of array
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        // min subarray sum
        int bestending = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            bestending = min(v1, v2);
            ans = min(ans, bestending);
        }
        if(ans == sum){
            return ans;
        }
        return sum-ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int A1 = maxSum(nums);
        int A2 = circularSum(nums);
        return max(A1, A2);
    }
};