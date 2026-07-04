class Solution {
public:

    int find(vector<int> &a){
            int maxCount = -1;
            for(int i=0; i<256; i++){
                maxCount=max(maxCount,a[i]);
            }
                return maxCount;
        }

    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256,0);

        int low=0, high=0, res=INT_MIN;
        for(high=0; high<n; high++){
            f[s[high]]++;
            int len = high-low+1;
            int maxCount = find(f);
            int diff = len-maxCount;

            while(diff>k){
                f[s[low]]--;
                low++;
                maxCount = find(f);
                len = high-low+1;
                diff = len-maxCount;

            }
             len = high-low+1;
             res = max(res, len);
        }
        return res;
    }
};