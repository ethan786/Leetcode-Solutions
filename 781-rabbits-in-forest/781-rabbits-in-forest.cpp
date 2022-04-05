class Solution {
public:
    int numRabbits(vector<int>& a) {
        int n = a.size();
        unordered_map<int,int> m;
        int ans = 0; 
        for(auto &i : a){
            m[i]++;
            if(i != 0 and m[i] > i + 1){
                ans += i+1;
                m[i] = 1;
            }
        }
        ans += m.size(); // those who answered the interview
        for(auto &i : m){
            if(i.first == 0){
                ans += i.second-1;
            }else{
                ans += i.first;
            }
        }
        return ans;
    }
};