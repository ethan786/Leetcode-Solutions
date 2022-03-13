class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> v(27,false);
        vector<int> lastOcc(27,-1);
        for(int i=0;i<n;i++){
            lastOcc[s[i]-'a'] = i;
        }
        stack<char> st;
        for(int i=0;i<n;i++){
            //cout<<v[s[i]-'a']<<" ";
            if(v[s[i]-'a'] == false){
                while(st.size() > 0 && st.top() > s[i] && i < lastOcc[st.top()-'a']){
                    //cout<<"suar";
                    v[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(s[i]);
                v[s[i]-'a'] = true;
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};