class Solution {
public:
    int solve(int i, string &s, int x, int y,int n){
       int c = 0;
           while(i<s.size() and x <= n-1 and y <= n-1 and x >= 0 and y >= 0){
               
               if(s[i] == 'R'){
                   y++;
               }else if(s[i] == 'L'){
                   y--;
               }else if(s[i] == 'U'){
                   x--;
               }else if(s[i] == 'D'){
                   x++;
               }
               if(x <= n-1 and y <= n-1 and x >= 0 and y >= 0){
                   i++;c++;
               }else{
                   return c;
               }
           } 
        return c;
    }
    
    vector<int> executeInstructions(int n, vector<int>& sp, string s) {
        int x = sp[0], y = sp[1];
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            int c = solve(i,s,x,y,n);
            ans.push_back(c);
        }
        return ans;
    }
};