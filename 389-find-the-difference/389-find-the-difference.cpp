class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char ans = 0;
        for(int i : s){
            ans ^= i;
        }
        for(int i : t){
            ans ^= i;
        }
        
        return ans;
    }
};