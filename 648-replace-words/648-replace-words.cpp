class Solution {
    struct Node{
       Node* link[26];
       bool f = false; 
    };
    class trie{
        private: Node* root;
        public: 
        trie(){
            root = new Node();
        }
        
        void insert(string s){
            Node* n = root;
            for(int i=0;i<s.size();i++){
                if(n->link[s[i]-'a'] == NULL){
                    n->link[s[i]-'a'] = new Node();
                }
                n = n->link[s[i]-'a'];
            }
            n->f = true;
        }
        string small(string s){
            string ans = "";
            Node* n = root;
            for(int i=0;i<s.size();i++){
                if(n->link[s[i]-'a'] == NULL){
                    return s;
                }else{
                    ans += s[i];
                    n = n->link[s[i]-'a'];
                    if(n->f){
                        return ans;
                    }
                }
            }
            return ans;
        }
    };
public:
    string replaceWords(vector<string>& d, string s) {
        trie t;
        for(auto &i : d){
            t.insert(i);
        }
        string ans = "";
        int i = 0;
        while(i < s.size()){
                string y = "";
                while(i<s.size() and s[i] != ' '){
                    y += s[i];
                    i++;
                }
                //cout<<i<<endl;
                string x = t.small(y);
                //cout<<x<<endl;
                if(x == ""){
                    ans += y;
                    ans += ' ';
                }
            
                if(y.size() > x.size()){
                    ans += x;
                }else{
                    ans += y;
                }
            
                if(s[i] == ' '){
                    ans += ' ';
                }
                i++;
        }
        return ans;  
    }
};