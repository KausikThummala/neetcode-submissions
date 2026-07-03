int sumofsquares(int a);
class Solution {
public:
    bool isHappy(int n) {
        //fast and slow pointer
        int fast=n;
        int slow=n;
        do{
            fast=sumofsquares(sumofsquares(fast));
            slow=sumofsquares(slow);
        } while(slow!=fast);
        if (slow==1){
            return true;
        }
        return false;
        
    }
};
int sumofsquares(int a){
    int res=0;
    while(a>0){
        int rem=a%10;
        res+=rem*rem;
        a=a/10;
    }
    return res;
}

