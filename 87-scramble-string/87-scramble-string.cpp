class Solution {
public:
    
    unordered_map<string,bool> mp;
    
    bool check(string a, string b){
        string key = a + " " + b;
        if (mp.find(key) != mp.end()) return mp[key];
        if(a==b) return mp[key]=true;
        if(a.length()<=1 || b.length()<=1) return mp[key]=false;
        int sum1=0;
        int sum2=0;
        for(int i=0; i<a.length(); i++){
            sum1=sum1+int(a[i]);
        }
        for(int i=0; i<b.length(); i++){
            sum2=sum2+int(b[i]);
        }
        if(sum1!=sum2) return mp[key]=false;
        
        int n=a.length();
        for(int i=1; i< a.length(); i++){
            if( check(a.substr(0,i),b.substr(0,i)) && check(a.substr(i,n-i),b.substr(i,n-i)) ){
                 return true;
                 break;
             }
            if( check(a.substr(0,i),b.substr(n-i,i)) && check(a.substr(i,n-i),b.substr(0,n-i))) {
                 return true;
                 break;
             }
        }
        return mp[key]=false;
        
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;        
        return check(s1,s2);
    }
};