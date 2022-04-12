class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char c = st.top();
                if(c == '(' and s[i] != ')') return false;
                else if(c == '[' and s[i] != ']') return false;
                else if(c == '{' and s[i] != '}') return false;
                st.pop();
            }
        }
        return st.size() == 0 ? true : false; 
    }
};