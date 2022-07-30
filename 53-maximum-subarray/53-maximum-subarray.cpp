class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        // like we have to maximize the sum 
        // so, instead of taking negative in the sum 
        // we will use postive element in the sum 
        // as possible
        int curSum = 0, ans = INT_MIN;
        
        for(auto &i : a) {
            curSum += i;
            ans = max(ans, curSum);
            if(curSum <= 0) {
                curSum = 0;
            }
        }
        
        return ans;
    }
};