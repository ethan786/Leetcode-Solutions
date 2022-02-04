class Solution {
public:
    unordered_map<long long int,long long int> mp;
    long long int solve(long long int n){
        if(n<=0) return 0;
        if(n==1) return 1;
        
        if(mp.count(n) > 0) return mp[n];
        
        long long int op3=INT_MAX;
        //op1 = 1 + solve(n-1);//no need of eating one day one orange
        //but to make n divisible by 2 nd 3 we will use n%2,3;
        // n/3 = n - 2n/3
        //n%3 -> 0,1,2 and n%2 -> 0,1
        op3 = 1 + (n%3) + solve(n/3);
        long long int op2 = 1 + (n%2) + solve(n/2);
        
        return mp[n] = min(op2,op3);
    }
    
    int minDays(int n) {
        return solve(n);
    }
};
