class Solution {
public:
    string maximumBinaryString(string s) {
        int o = 0,z = 0;
        for(auto &i : s){
            if(i == '1'){
                o++;
            }else{
                z++;
            }
        }
        int x = 0;
        for(auto &i : s){
            if(i == '0'){
                break;
            }
            x++;
        }
        string ans = "";
        if(z == 0){
            return s;
        }else{
            for(int i=0;i<x;i++){
                ans += '1';
            }
            z--;
            for(int i=0;i<z;i++){
                ans += '1';
            }
            ans += '0';
            for(int i=0;s.size()>ans.size();i++){
                ans += '1';
            }
        }
        return ans;
    }
};