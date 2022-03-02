class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m < n || m == n){
            return s == t;
        }
        int i = 0,j = 0;
        while(j<m){
            if(s[i] == t[j]){
                i++;j++;
            }else{
                j++;
            }
            if(i == n){
                return true;
            }
        }
        return false;
    }
};
