class Solution {
public:
    int countSubstrings(string s, string t) {
        int count = 0;
        int n = s.size();
        int m = t.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = i;
                int y = j;
                int differBy = 0;
                while(x<n and y<m){
                    if(s[x] != t[y]){
                        differBy++;
                    }
                    if(differBy == 1){
                        count++;
                    }
                    if(differBy > 1){
                        break;
                    }
                    x++;
                    y++;
                }
            }
        }
        return count;
    }
};
//abc
//bce ( 4!/3!*1! = 4 + 2
//i j differby >2 break
//else count++;
//n*m*max(n,m) ~ 100*100*100 = 10^6 