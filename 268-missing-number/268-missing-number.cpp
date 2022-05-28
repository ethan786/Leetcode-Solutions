class Solution {
public:
    int missingNumber(vector<int>& a) {
        int sum = 0;
        for(int i = 0; i < a.size(); ++i) {
            sum += a[i];
        }
        int n = a.size();
        long long os = n * (n + 1);
        os /= 2;
        return os - sum;
    }
};