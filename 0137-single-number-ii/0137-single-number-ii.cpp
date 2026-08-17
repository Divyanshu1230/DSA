class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =0;

        for(int k=0; k<=31; k++){
            int temp = (1 << k);
            int cntOnes=0;
            for(int &num : nums){
                if((num&temp) !=0){
                    cntOnes++;
                }
            }
            if(cntOnes % 3==1){
                res = (res | temp);
            }
        }
        return res;
    }
};