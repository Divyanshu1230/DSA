class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxE=0, chunk=0;
        for(int i=0; i<arr.size(); i++){
            maxE=max(maxE,arr[i]);
            if(maxE==i){
                chunk++;
            }
        }
        return chunk;
    }
};