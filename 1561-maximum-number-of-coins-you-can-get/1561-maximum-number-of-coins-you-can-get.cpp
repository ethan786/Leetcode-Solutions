class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(),p.end());
        int n = p.size();
        int x = n/3;
        int sum = 0;
        while(x--){
            sum += p[n-2];
            n-=2;
        }
        return sum;
    }
};
