class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n+1,false);
        for(int i=0;i<n;i++){
            v[nums[i]] = true;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(v[i] == false){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};