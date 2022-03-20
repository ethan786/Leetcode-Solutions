struct Node{
    int s = 0;
    Node* link[26];
};
class MapSum {
    Node* root;
public:
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* node = root;
        for(int i=0;i<key.size();i++){
            if(node->link[key[i]-'a'] == NULL){
                node->link[key[i]-'a'] = new Node();
            }
            node = node->link[key[i]-'a'];
        }
        node->s = val;
    }
    
    int sum(string key) {
        Node* node = root;
        for(int i=0;i<key.size();i++){
            if(node->link[key[i]-'a'] == NULL){
                return 0;
            }
            node = node->link[key[i]-'a'];
        }
        return dfs(node);
    }
    
    int dfs(Node* node){
        int sum = 0;
        for(int i=0;i<26;i++){
            if(node->link[i] != NULL){
                sum += dfs(node->link[i]);
            }
        }
        return sum + node->s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */