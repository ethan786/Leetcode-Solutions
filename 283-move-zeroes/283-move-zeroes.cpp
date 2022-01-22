class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1||n==0) return;
        int i=0,j=1;
        while(j<n){
            if(nums[i] == 0 and nums[j] == 0){
                j++;
            }else if(nums[i] == 0){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i++;j++;
            }else{
                i++;j++;
            }
        }
        
    }
};