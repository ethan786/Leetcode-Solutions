class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> l(26,0);
        for(int i=0;i<s.size();i++){
            l[s[i]-'a'] = i;
        }
        int newStart = 0,x = -56789;
        for(int i=0;i<s.size();i++){
            x = max(x,l[s[i]-'a']);
            if(i == x){
                ans.push_back(i-newStart+1);
                newStart = i+1;
            }
        }
        return ans;
    }
};