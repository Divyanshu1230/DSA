class Solution {
public:
    int M = 1e9+7;
    int numSub(string s) {
        int n= s.size();
        int cnt = 0;
        int ans = 0;
        for(char ch: s){
            if(ch=='1'){
                cnt++;
                ans = (ans+cnt) % M;
            } else {
                cnt=0;
            }
        }
        return ans;
    }
};