class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,-1);
        for(int i=0;i<s.size();i++){
            last[s[i] - 'a'] = i; 
        }
        int i = 0, j = 0,sum = 0;
        vector<int> ans;
        while(i < s.size()){
            j = max(j,last[s[i]-'a']);
            if(i == j){
                if(ans.size() == 0){
                    ans.push_back(j+1);
                    sum += j+1;
                }else{
                    ans.push_back(j-sum+1);
                    sum += ans[ans.size()-1];
                }
            }
            i++;
        }
        return ans;
    }
};