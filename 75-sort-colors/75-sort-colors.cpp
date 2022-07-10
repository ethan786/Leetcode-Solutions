class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(3,0); // 0 1 2
        for(auto &i : nums) {
            freq[i]++;
        }
        int k = 0;
        for(int i = 0; i < 3; i++) {
            int count = freq[i];
            for(int j = 0; j < count; j++) {
                nums[k++] = i;
            }
        }
        
    }
};