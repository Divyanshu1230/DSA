class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int low=0;
        long long sum=0;
        long long maxSum = 0;
        unordered_map<int,int> f;

        for(int high=0; high<n; high++){
            sum+=nums[high];
            f[nums[high]]++;

            if(high-low+1>k){
                f[nums[low]]--;
                sum-=nums[low];

                if(f[nums[low]]==0){
                    f.erase(nums[low]);
                }
                low++;
            }

            if(high-low+1==k){
                if(f.size()==k){
                    maxSum= max(maxSum,sum);
                }
            }
        }
        return maxSum;
    }
};