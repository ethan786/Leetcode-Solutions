class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for(auto &i : words) {
            string s = "";
            for(auto &j : i) {
                s += map[j-'a'];
            }
            ans.insert(s);
        }
        return ans.size();
    }
};