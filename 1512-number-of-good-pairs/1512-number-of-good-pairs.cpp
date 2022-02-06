class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        for(auto i : nums){
            m[i]++;
        }
        int ans = 0;
        for(auto i : m){
            int j = i.second;
            ans += (j*(j-1))/2;
        }
        return ans;
    }
};
//nC2 = 