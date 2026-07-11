class Solution {
public:

    bool isValid(char ch){
        ch = tolower(ch);
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    string reverseVowels(string s) {
        int left = 0, right=s.length()-1;
        while(left<right){
            if(left<right && !isValid(s[left])){
                left++;
            }
            else if(left<right && !isValid(s[right])){
                right--;
            }
            else {
                swap(s[left], s[right]);
                left++, right--;
            }
            
        }
        return s;
    }
};