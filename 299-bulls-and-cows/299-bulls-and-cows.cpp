class Solution {
public:
    string getHint(string s, string g) {
        vector<int> c(10,0);
        vector<int> b(10,0);
        int bulls = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == g[i]){
                bulls++;
            }else{
                c[s[i]-'0']++;
                b[g[i]-'0']++;
            }
        }
        // abb cows ke liye
        int cows = 0;
        for(int i=0;i<10;i++){
            cows += min(c[i],b[i]);
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};