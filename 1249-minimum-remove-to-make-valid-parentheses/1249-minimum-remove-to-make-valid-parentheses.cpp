class Solution {
public:
    // string minRemoveToMakeValid(string s) {
    //     stack<char> st;
    //     string ans = "";
    //     for(int i=0;i<s.size();i++){
    //         if(s[i] == ')'){
    //             if(!st.empty() and st.top() == '('){
    //                 ans += s[i];
    //                 st.pop();
    //             }
    //         }else{
    //             if(s[i] == '('){
    //                 st.push(s[i]);
    //                 ans += s[i];
    //             }else{
    //                 ans += s[i];
    //             }
    //         }
    //         //cout<<ans<<endl;
    //     }
    //     int x = st.size();
    //     int j = s.size() - 1;
    //     while(x){
    //         if(ans[j] == '('){
    //             ans.erase(j,1);
    //             x--;
    //         }
    //         j--;
    //     }
    //     return ans;
    // }
     string minRemoveToMakeValid(string s)
    {
        int i = s.size();
        int balance = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == ')') balance++;
            else if (s[j] == '(') {
                if (balance == 0) continue;
                balance--;
            }
            s[--i] = s[j];
        }
        int len = 0;
        balance = 0;
        for (; i < s.size(); i++) {
            if (s[i] == '(') balance++;
            else if (s[i] == ')') {
                if (balance == 0) continue;
                balance--;
            }
            s[len++] = s[i];
        }
        s.erase(len);
        return s;
    }
    
};