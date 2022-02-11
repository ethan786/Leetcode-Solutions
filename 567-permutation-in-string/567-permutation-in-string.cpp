// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n = s1.size();
//         int m = s2.size();
//         int s1map[26],s2map[26];
//         for(int i=0;i<n;i++){
//             s1map[s1[i]-'a']++;
//             s2map[s2[i]-'a']++;
//         }
//         int count = 0;
//         for(int i=0;i<26;i++){
//             if(s1map[i] == s2map[i]) count++;
//         }
//         for(int i=0;i<m-n;i++){
//             int r = s2[i+n] - 'a',l = s2[i] - 'a';
//             if(count == 26) return true;
//             s2map[r]++;
//             if(s1map[r] == s2map[r]) count++;
//             else if(s1map[r] + 1 == s2map[r]) count--;
//             s2map[l]--;
//             if(s1map[l] == s2map[l]) count++;
//             else if(s1map[l] - 1 == s2map[l]) count--;
            
//         }
//         return count == 26;
//     }
// };
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {0};
        for(char c : s1) map[c - 'a']++;
        int j = 0, i = 0, count_chars = s1.size();
        while(j < s2.size()){
            if(map[s2.at(j++) - 'a']-- > 0)
                count_chars--;
            if(count_chars == 0) return true;
            if(j - i == s1.size() && map[s2.at(i++) - 'a']++ >= 0)
                count_chars++;
        }
        return false;
    }
};