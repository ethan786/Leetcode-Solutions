class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0,c=0;
        while(s[n-1] == ' '){
            n--;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] != ' '){
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};