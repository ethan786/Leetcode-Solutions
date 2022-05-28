class Solution {
public:
    /* maths solution
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
    */
    /*
    bit manipulation
    int missingNumber(vector<int>& a) {
        int ans = 0;
        for(int i = 0; i < a.size(); ++i) {
            ans ^= i ^ a[i];
        }
        return ans^a.size();
    }
    */
    
    // sum of index - sum of num
    int missingNumber(vector<int>& nums) {
        int sum=0,n=nums.size(),sum_n=0;
        for(int i=0;i<n; i++) sum+=nums[i];
        for(int i=1;i<=n;i++) sum_n+=i;
        return sum_n-sum;
    }
    
};