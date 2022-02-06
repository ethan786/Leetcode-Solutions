class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return n;
        int i=2,j=2;
        int c = 1;
        while(i<n){
            if(nums[j-2] != nums[i]){
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};