class Solution {
public:
    bool fun(vector<int>& nums, int n, int limit, int k){
        int student = 1, page=0;
        for(int i=0; i<nums.size(); i++){
            if(page+nums[i]<=limit){
                page+=nums[i];
            } else {
                student++;
                page=nums[i];
                if(student>k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            return -1;
        }
        int low=0, high=0;
        for(int i=0; i<n; i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        int res=-1;
        while(low<=high){
            int guess = (low+high)/2;
            if(fun(nums,n,guess,k)){
                res=guess;
                high=guess-1;
            } else {
                low=guess+1;
            }
        }
        return res;
    }
};