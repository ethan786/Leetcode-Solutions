class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i+1 != nums[i]){ // means not at correct position
                while(nums[i] != i+1){
                    int nextpos = nums[i]-1;
                    if(nums[nextpos] == nums[i]){
                        break;
                    }
                    //swap
                    int temp = nums[i];
                    nums[i] = nums[nextpos];
                    nums[nextpos] = temp;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                ans.emplace_back(i+1);
            }
        }
        return ans;
    }
};