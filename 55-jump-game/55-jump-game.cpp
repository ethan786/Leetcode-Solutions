class Solution {
public:
    
    // bool solve(int i,int n,vector<int> &nums){
    //     if(i>=n-1){
    //         return true;
    //     }
    //     if(nums[i] == 0) return false;
    //     int max_range = nums[i]+i;
    //     for(int j = i+1;j<=max_range;j++){
    //         if(solve(j,n,nums)) return true;
    //     }
    //     return false;
    // }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int min_jumps_required = 0;
        for(int i=n-2;i>=0;i--){
            min_jumps_required++;
            if(nums[i]>=min_jumps_required){
                min_jumps_required=0;
            }
        }
        
        return min_jumps_required==0 ? true : false ;
    }
};