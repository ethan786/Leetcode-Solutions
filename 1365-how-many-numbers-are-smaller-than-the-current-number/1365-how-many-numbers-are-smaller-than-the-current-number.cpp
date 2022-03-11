// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<pair<int,int>> p;
//         int n = nums.size();
//         for(int i= 0; i<n;i++){
//             p.push_back({nums[i],i});
//         }
//         sort(p.begin(),p.end());
//         vector<int> v(n);
//         for(int i = 0;i<n;i++){
//             auto j = p[i];
//             if(p.first )
//             v[j.second] = i; 
//         }
//         return v;
//     }
// };    
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums.size(); j++)
                if (nums[i] > nums[j])
                    ans[i]++;
                else if (nums[i] == nums[j])
                    continue;
        return ans;
    }
};