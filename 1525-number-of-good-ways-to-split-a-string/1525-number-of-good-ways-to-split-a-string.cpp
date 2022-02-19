class Solution {
public:
    
    int numSplits(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> pref(n);
        vector<int> suf(n);
        vector<int> v(26,0);
        
        for(int i=0;i<n-1;i++){
            if(v[s[i]-'a'] == 0){
                v[s[i]-'a']++;
                (i>0) ? pref[i] = pref[i-1] + 1 : pref[i] = 1;
            }else{
                pref[i] = pref[i-1];
            }
        }
        fill(v.begin(), v.end(), 0);
        for(int i=n-1;i>0;i--){
            if(v[s[i]-'a'] == 0){
                v[s[i]-'a']++;
                (i+1<n) ? suf[i] = suf[i+1] + 1 : suf[i] = 1;
            }else{
                suf[i] = suf[i+1];
            }
        }
        for(int i=0;i<n-1;i++){
            if(pref[i] == suf[i+1]){
                ans++;
            }
        }
        return ans;
    }
};