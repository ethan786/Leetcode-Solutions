class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        int pn = 0,pp = 0;
        for(int i=0;i<n-1;i++){
            int dif = nums[i+1]-nums[i];
            if(dif > 0){
                pp = pn +1;
            }else if(dif < 0){
                pn = pp + 1;
            }
        }
        return max(pp,pn) + 1;
    }
};

   
    