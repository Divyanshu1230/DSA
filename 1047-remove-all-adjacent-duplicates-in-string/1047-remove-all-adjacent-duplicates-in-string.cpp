class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        string ans = "";
        for(char c : s){
            if(st.empty() || st.top() != c){
                st.push(c);
            } else {
                st.pop();
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};