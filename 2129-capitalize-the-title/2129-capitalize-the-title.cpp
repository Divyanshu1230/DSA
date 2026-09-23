class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int i =0;

        while(i<n){
            int st = i;

            while(i<n && title[i] != ' '){
                i++;
            }
            int len = i - st;
            for(int j = st; j<i; j++){
                title[j]=tolower(title[j]);
            }
            if(len>=3){
                title[st]=toupper(title[st]);
            }
            i++;
        }
        return title;
    }
};