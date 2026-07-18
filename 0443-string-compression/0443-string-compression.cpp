class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        int i = 0;

        while(i<n){
            char ch = chars[i];
            int cnt = 0;

            while(i<n && chars[i] == ch){
                cnt++, i++;
            }
            if(cnt==1){
                chars[idx++]=ch;
            } else {
                chars[idx++] = ch;
                string str = to_string(cnt);
                for(char dig:str){
                    chars[idx++]=dig;
                }
            }
        }
        return idx;
    }
};