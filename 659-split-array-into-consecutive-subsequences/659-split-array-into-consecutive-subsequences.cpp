class Solution {
public:
    bool isPossible(vector<int>& a) {
        int n = a.size();
        map<int,int> m, last;
        for(auto &i : a) m[i]++;
        for(int i = 0; i < n; i++) {
            int num = a[i];
            if(m[num] == 0) continue;
            m[num]--;
            if(last[num-1] != 0) {
                last[num-1]--;
                last[num]++;
            }else if(m[num+1] != 0 and m[num+2] != 0){
                m[num+1]--;
                m[num+2]--;
                last[num+2]++;
            }else {
                return false;
            }
        }
        return true;
    }
};