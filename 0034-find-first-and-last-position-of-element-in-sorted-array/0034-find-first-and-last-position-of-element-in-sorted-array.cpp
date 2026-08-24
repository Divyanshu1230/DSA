class Solution {
public:
    // first element
    int findFirst(vector<int>& nums, int target){
        int n = nums.size();
        int low=0, high=n-1;
        int ans = -1;
        while(low<=high){
            int guess = (high+low)/2;
            if(nums[guess]<target){
                low=guess+1;
            } else if(nums[guess]>target){
                high=guess-1;
            } else {
                ans=guess;
                high=guess-1;
            }
        }
        return ans;
    }

    // second element
    int findLast(vector<int>& nums, int target){
        int n = nums.size();
        int low=0, high=n-1;
        int ans = -1;
        while(low<=high){
            int guess = (high+low)/2;
            if(nums[guess]<target){
                low=guess+1;
            } else if(nums[guess]>target){
                high=guess-1;
            } else {
                ans=guess;
                low=guess+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums,target);
        int last = findLast(nums,target);

        return {first, last};
    }
};