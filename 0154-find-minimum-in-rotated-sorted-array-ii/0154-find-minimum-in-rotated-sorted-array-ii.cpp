class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end=n-1;
        sort(nums.begin(), nums.end());
        while(st<end){
            if(nums[st]<=nums[end]){
                return nums[st];
            }
        }
        return 1;
    }
};