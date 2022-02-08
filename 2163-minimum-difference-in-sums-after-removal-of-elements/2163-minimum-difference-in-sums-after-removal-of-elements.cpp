class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n,0);
        priority_queue<int> left;
        long long sum = 0;
        priority_queue<int,vector<int>,greater<int>> right;
        //maximum sum of n element from right
        for(int i = n - 1;i >= (n / 3); i--){
            right.push(nums[i]);
            sum += nums[i];
            if(right.size() > (n / 3)){
                sum  -= right.top();
                right.pop();
            }
            pref[i] = sum;
        }
        //calculating answer by insert minimum sum from left
        // for(int i=0;i<n;i++){
        //     cout<<pref[i]<<" ";
        // }
        long long ans = 1e10;
        sum = 0;
        for(int i = 0; i < n - (n / 3); i++){
            left.push(nums[i]);
            sum += nums[i];
            //cout<<left.size()<<" "<<i<<endl;
            if(left.size() == (n / 3)){
                //cout<<sum<<pref[i+1]<<endl;
                ans = min(ans,sum - pref[i+1]);
            }
            if(left.size() > (n / 3)){
                sum -= left.top();
                ans = min(ans,sum - pref[i+1]);
                left.pop();
            }
        }
        return ans;
    }
};