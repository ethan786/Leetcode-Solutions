class Solution {
public:
    int integerBreak(int n) {
        
        if(n<=3) return n-1;
        
        int pro = 1;
        while(n>4){
            n-=3;
            pro *= 3;
        }
        
        return pro*n;
    }
};