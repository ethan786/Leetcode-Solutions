class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int i = 0, j = a.size() - 1;
        while(i < j) {
            int sum = a[i] + a[j];
            if(sum == target) {
                return {i+1, j+1};
            }else if(sum > target) {
                j--;
            }else {
                i++;
            }
            
        }
        return {};
    }
};