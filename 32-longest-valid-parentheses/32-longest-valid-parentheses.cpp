class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        stack<int> a;
        a.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                a.push(i);
            }else {
                a.pop();
                if(a.empty()){
                    a.push(i);
                }else{
                    result = max(result,i-a.top());
                }
            }
        }
        return result;
    }
};