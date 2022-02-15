class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int x = nums[0];
        m[nums[0]]++;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(m[nums[i]] < 2){
                x ^= nums[i];
                m[nums[i]]++;
            }
        }
        return x;
    }
};