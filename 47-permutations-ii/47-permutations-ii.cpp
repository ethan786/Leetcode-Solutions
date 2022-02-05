class Solution{
    public:
 void fun(int i,vector<int> &nums, vector<vector<int>> &ans){
        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        set<int> s;
        for(int j=i;j<nums.size();j++){
            if(s.count(nums[j])) continue;
            s.insert(nums[j]);
            
            swap(nums[i],nums[j]);
            fun(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        fun(0,nums,ans);
        return ans;
    }
};