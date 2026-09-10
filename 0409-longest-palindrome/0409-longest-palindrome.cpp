class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        for(int i=0; i<s.size(); i++){
            f[s[i]]++;
        }
        bool odd = false;
        int ans = 0;

        for(auto i:f){
            int val = i.second;
            if(val%2==0){
                ans+=val;
            } else {
                odd = true;
            }
        }
        if(odd==false){
            return ans;
        }
        for(auto i:f){
            int val = i.second;
            if(val%2==1){
                ans+=val-1;
            }
        }
        return ans+1;
    }
};