class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        long long product=1;
        int ans = 0;

        if(k<=1) return 0;

        for(int high=0; high<n; high++){
            product*=nums[high];

            while(product>=k){
                product/=nums[low];
                low++;
            }
            ans+=high-low+1;
        }
        return ans;
    }
};