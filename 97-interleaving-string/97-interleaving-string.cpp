class Solution {
public:
    unordered_map<string,bool> m;
    bool solve(string s1, string s2, string s3,int l1,int l2,int l3,int p1,int p2,int p3){
        //base case
        if(p3 == l3){
            return (p1 == l1 and p2 == l2);
        }
        //unique making
        string key = to_string(p1)+to_string(p2)+to_string(p3);
        if(m.find(key) != m.end()) return m[key];
        
        if(p1 == l1){
            return m[key] = s2[p2] == s3[p3] ? solve(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1) : false;
        }
        if(p2 == l2){
            return m[key] = s1[p1] == s3[p3] ? solve(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1) : false;
        }
        bool op1 = false,op2 = false;
        if(s1[p1] == s3[p3]){
            op1 = solve(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        }
        if(s2[p2] == s3[p3]){
            op2 = solve(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        }
        return m[key] = op1 || op2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1,s2,s3,s1.size(),s2.size(),s3.size(),0,0,0);
    }
};