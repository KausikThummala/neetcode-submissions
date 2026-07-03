#include <vector>
int countbits(int a);
class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> temp;
        temp.push_back(0);
        for(int i=1;i<=n;i++){
            temp.push_back(countbits(i));

        }
        return temp;

        
    }
};
int countbits(int a){
    int c=0;
    while(a>0){
        a=a&(a-1);
        c+=1;
    }
    return c;
}
