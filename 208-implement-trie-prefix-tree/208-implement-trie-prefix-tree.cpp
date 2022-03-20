struct Node{
    Node* link[26];
    bool f = false;
    
    bool containKey(char c){
        return link[c - 'a'] != NULL;
    }
    
    void put(char c,Node* n){
        link[c - 'a'] = n;
    }
    
    Node* get(char c){
        return link[c - 'a'];
    }
    
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->f = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->f == true;
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */