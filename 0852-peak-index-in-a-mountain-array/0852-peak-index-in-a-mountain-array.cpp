class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0, high=arr.size()-1;
        int ans = -1;
        while(low<=high){
            int guess = (low+high)/2;
            if(arr[guess]<arr[guess+1]){
                low=guess+1;
            } else {
                ans = guess;
                high=guess-1;
            }
        }
        return ans;
    }
};