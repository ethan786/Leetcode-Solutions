class Solution {
public:
    int integerBreak(int n) {
        int ans =INT_MIN;
        if(n==2) return 1;
       for(int i=2;i<n;i++){
           int x = n/i;
           int t = x;
           int rem = n%i;
           int product = 1;
           int in = i;
           while(rem>0){
               product = product * (x+1);
               rem--;
               in--;
           }
           while(in){
               product = product * t;
               in--;
           }
           //cout<<i<<" "<<product<<endl;
           ans = max(ans,product);
       }
        return ans;
    }
};