class Solution {
public:
    int hammingWeight(uint32_t n) {
        //need to find the number of set bits using hamming weight
        int c=0;
        while(n>0){
            n=n&(n-1);
            c+=1;
        }
        return c;


    }
};
