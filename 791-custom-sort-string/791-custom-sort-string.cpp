class Solution {
public:
    string customSortString(string o, string s) {
        string ans = "";
        int f[26];
        memset(f,0,sizeof(f));
        for(auto &i : s){
            f[i-'a']++;
        }
        for(auto &i : o){
            while(f[i-'a'] > 0){
                ans += i;
                f[i-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            while(f[i] > 0){
                ans += i + 'a';
                f[i]--;
            }
        }
        return ans;
    }
};