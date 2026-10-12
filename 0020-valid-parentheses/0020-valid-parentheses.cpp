class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c : s){ // opnining brackets
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            } else {  // closing brackets
                if(st.empty()) return false;

                if(c==')' && st.top() != '(') return false;
                if(c==']' && st.top() != '[') return false;
                if(c=='}' && st.top() != '{') return false;

                st.pop();
            }
        }
        return st.empty();
    }
};