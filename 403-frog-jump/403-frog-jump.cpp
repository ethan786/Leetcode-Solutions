class Solution {
public:
    map<pair<int,int>,bool> dp; 
    int search(vector<int> &s,int pos){
        int st = 0;
        int e = s.size()-1;
        while(st<=e){
            int mid = st + (e-st)/2;
            if(s[mid] == pos){
                return mid;
            }else if(s[mid] > pos){
                e = mid -1;
            }else{
                st = mid+1;
            }
        }
        return -1;
    }
    bool solve(vector<int>& s,int k,int n,int i,int pos){
        if(i == n-1){
            return true;
        }else if(search(s,pos)==-1){ 
            return false;
        }else if(i>=n){
            return false;
        }
        if(dp.find({pos,k})!=dp.end()) return dp[{pos,k}];
        int jumps = k+pos;
        int nextjumpindex1 = search(s,jumps);
        bool op1 = false;
        if(nextjumpindex1){
         op1 = solve(s,k,n,nextjumpindex1,pos+k); 
        }
        bool op2 = false;
        if(k!=1){
            int jump_back = k+pos-1;
            int nextjumpindex2 = search(s,jump_back);
            if(nextjumpindex1){
                 op2 = solve(s,k-1,n,nextjumpindex2,k+pos-1);
            }
        }
        int jump_ahead = k+pos+1;
        int nextjumpindex3 = search(s,jump_ahead);
        bool op3 = false;
        if(nextjumpindex3){
             op3 = solve(s,k+1,n,nextjumpindex3,k+pos+1);
        }
        return dp[{pos,k}] = op1 || op2 || op3;   
    }
    
    bool canCross(vector<int>& s) {
        int n = s.size();
        if(n==2 and s[1] > 1){
            return false;
        }
        int pos = 1;
        return solve(s,1,n,1,pos);
    }
};