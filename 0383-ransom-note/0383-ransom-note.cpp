class Solution {
public:

    // bool fun(unordered_map<char,int> &need, unordered_map<char,int> &have){
    //     for(auto i: need){
    //         char c = i.first;
    //         int fneed = i.second;
    //         int fhave = have[c];
    //         if(fhave<fneed) return false;
    //     }
    //     return true;
    // }

    bool canConstruct(string ransomNote, string magazine) {
        int n1 = ransomNote.size(); //need
        int n2 = magazine.size(); //have
        unordered_map<char,int> need;
        unordered_map<char,int> have;
        for(int i=0; i<n1; i++){
            need[ransomNote[i]]++;
        }
        for(int i=0; i<n2; i++){
            have[magazine[i]]++;
        }

        for(auto i: need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if(fhave<fneed){
                return false;
            }
        }
        return true;
    }
};